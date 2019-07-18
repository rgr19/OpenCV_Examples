/*
 * AppendVids: Attach 2 videos one after the other. By Shervin Emami (shervin.emami@gmail.com) on 27th April 2010.
 *	"http://www.shervinemami.co.cc/"
 */

#define CV_NO_BACKWARD_COMPATIBILITY


#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "opencv2/opencv.hpp"
#include <iostream>

#include "ImageUtils.h"		// ImageUtils by Shervin Emami on 20th Feb 2010.


int FPS;  // Usually 25 or 30 fps.		// Speed of saved video stream.
int width;
int height;
int FPS1;  // Usually 25 or 30 fps.		// Speed of saved video stream.
int movieWidth1;
int movieHeight1;
int FPS2;  // Usually 25 or 30 fps.		// Speed of saved video stream.
int movieWidth2;
int movieHeight2;

int imageFolderMode = FALSE;


// Record the execution time of some code. By Shervin Emami.
// eg:
//	DECLARE_TIMING(myTimer);
//	START_TIMING(myTimer);
//	printf("Hello!\n");
//	STOP_TIMING(myTimer);
//	printf("Time: %f ms\n", GET_TIMING(myTimer) );
#define DECLARE_TIMING(s)		double timeStart_##s; double timeDiff_##s; double timeTally_##s = 0; int countTally_##s = 0
#define START_TIMING(s)			timeStart_##s = (double)cvGetTickCount()
#define STOP_TIMING(s)			timeDiff_##s = (double)cvGetTickCount() - timeStart_##s; timeTally_##s += timeDiff_##s; countTally_##s++
#define GET_TIMING(s)			(double)(timeDiff_##s / (cvGetTickFrequency()*1000.0))
#define GET_AVERAGE_TIMING(s)	(double)(countTally_##s ? timeTally_##s / ((double)countTally_##s * cvGetTickFrequency()*1000.0) : 0)


CvCapture* capture1 = 0;
CvCapture* capture2 = 0;
CvVideoWriter *videoWriter = 0;



int runAppendVids(int argc, char **argv)
{
	IplImage *imageOut = 0;
	IplImage *frame1;
	IplImage *frame2;
	int iterations = 0;
	CvSize size;
	int i;
	int B = 4;	// border size.
	double timeDiff_wholeFrameInOut;
	double timeStart_wholeFrameInOut;
	double currentFrame_ms;

    // Print a welcome message, and the OpenCV version.
    printf ("Welcome to AppendVids, compiled with OpenCV version %s (%d.%d.%d)\n"
		"AppendVids: Attach 2 videos one after the other. By Shervin Emami (shervin.emami@gmail.com) on 27th April 2010.\n\n",
	    CV_VERSION, CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION);
	printf("usage:  AppendVids <input_video1>|<image_folder1> [<input_video2>] [output_video] [--FPS <fps>]\n\n");

	// Get the input video source, from a camera or a video file
	if( argc >= 2 ) {
        capture1 = cvCaptureFromAVI( argv[1] );
	}
	if( argc >= 3 ) {
        capture2 = cvCaptureFromAVI( argv[2] );
	}
	if (!capture1) {
		fprintf(stdout, "Could not open video file 1.\n");
		fprintf(stdout, "Will try to read all images in a folder using the given printf formatted path instead.\n");
		imageFolderMode = TRUE;
	}
	if (!capture2) {
		fprintf(stderr, "Could not open video file 2.\n");
		//return -1;
	}

	// Set the desired video file speed.
	if (capture1) {
		FPS1 = cvRound( cvGetCaptureProperty(capture1, CV_CAP_PROP_FPS) );
	}
	if (FPS1 <= 0 || FPS1 > 200) {
		FPS1 = 25;
	}
	if (capture2) {
		FPS2 = cvRound( cvGetCaptureProperty(capture2, CV_CAP_PROP_FPS) );
	}
	if (FPS2 <= 0 || FPS2 > 200) {
		FPS2 = 25;
	}
	FPS = max(FPS1, FPS2);	// Use the fastest video speed.

	// Check the flags on the command line.
	for (i=1; i<argc; i++) {
		if (_strcmpi(argv[i], "--FPS") == 0) {
			FPS = atoi(argv[i+1]);
		}
	}

	if (FPS <= 0 || FPS > 100)
		FPS = 25;

	// Get an initial frame so we know what size the image will be. 
	if (capture1) {
		frame1 = cvQueryFrame( capture1 );
	}
	else {
		// Try to load an image file instead of a video
		char filename[512];
		sprintf(filename, argv[1], iterations);
		printf("Trying to load image file '%s'\n", filename);
		frame1 = cvLoadImage( filename, CV_LOAD_IMAGE_COLOR );
	}
	if (!frame1) {
		fprintf(stderr, "Could not access video file 1.\n");
		return -1;
	}
	movieWidth1 = frame1->width;
	movieHeight1 = frame1->height;
	printf("Got a video source 1 with a resolution of %dx%d at %d fps.\n", movieWidth1, movieHeight1, FPS1);
	if (capture2) {
		frame2 = cvQueryFrame( capture2 );
		if (!frame2) {
			fprintf(stderr, "Could not acess video file 2.\n");
			return -1;
		}
		movieWidth2 = frame2->width;
		movieHeight2 = frame2->height;
		printf("Got a video source 2 with a resolution of %dx%d at %d fps.\n", movieWidth2, movieHeight2, FPS2);
	}

	width = max(movieWidth1, movieWidth2);
	height = max(movieHeight1, movieHeight2);
	size = cvSize(width, height);
    imageOut = cvCreateImage( size, 8, 3 );	// RGB image
    imageOut->origin = frame1->origin;
	printf("Combining the videos into a resolution of %dx%d at %d fps.\n", width, height, FPS);

	// Create a video output file if desired
	if (argc >= 4 && argv[2][0] != '-') {
		//int fourCC_code = CV_FOURCC('M','J','P','G');	// M-JPEG codec (apparently isn't very reliable)
		//int fourCC_code = CV_FOURCC('P','I','M','1');	// MPEG 1 codec
		int fourCC_code = CV_FOURCC('D','I','V','3');	// MPEG 4.3 codec
		//int fourCC_code = CV_FOURCC('I','2','6','3');	// H263I codec
		//int fourCC_code = CV_FOURCC('F','L','V','1');	// FLV1 codec
		int isColor = 1;				
		printf("Storing the video into '%s'\n", argv[3]);
		videoWriter = cvCreateVideoWriter(argv[3], fourCC_code, FPS, size, isColor);
	}

    printf( "Hot keys: \n"
            "\t ESC - quit the program\n"
            );

    cvNamedWindow( "AppendVids", 1 );

	printf("Processing the 1st input stream ... \n");
	iterations = 0;
	while (1)
    {
		int delay_ms;
		int c;

		timeStart_wholeFrameInOut = (double)cvGetTickCount();

		// Capture the frame, either from the camera or video file
		if (iterations > 0) {	// Use the first frame that was already obtained during initialization.
			if (capture1) {
				frame1 = cvQueryFrame( capture1 );
			}
			else {
				// Try to load an image file instead of a video
				char filename[512];
				sprintf(filename, argv[1], iterations);
				printf("Trying to load image file '%s'\n", filename);
				frame1 = cvLoadImage( filename, CV_LOAD_IMAGE_COLOR );
			}
			if( !frame1 )
				break;
		}

		// Either save to a video file or display on the screen
		if (videoWriter) {
			// Save to the output video file
			cvWriteFrame(videoWriter, frame1);      // stabilized image
		}
		//else {
			// Display an image on the GUI
			cvShowImage( "AppendVids", frame1 );	// stabilized image
		//}

		// Make sure the video runs at roughly the correct speed.
		// Add a delay that would result in roughly the desired frames per second.
		timeDiff_wholeFrameInOut = (double)cvGetTickCount() - timeStart_wholeFrameInOut;
		currentFrame_ms = (double)(timeDiff_wholeFrameInOut / (cvGetTickFrequency()*1000.0));
		delay_ms = cvRound((1000 / FPS) - currentFrame_ms);	// Factor in how much time was used to process this frame already.
		if (delay_ms < 1)
			delay_ms = 1;	// Make sure there is atleast some delay, to allow OpenCV to do its internal processing.
		c = cvWaitKey(delay_ms);	// Wait for a keypress, and let OpenCV display its GUI.

		if( (char)c == 27 )	// Check if the user hit the 'Escape' key
            break;	// Quit

		// If the frame was from an image and not a video, then free its resources.
		if (imageFolderMode)
			cvReleaseImage(&frame1);

		iterations++;
	}

	if (capture2) {
		printf("Processing the 2nd input stream ... \n");
		iterations = 0;
		while (1)
		{
			int delay_ms;
			int c;

			timeStart_wholeFrameInOut = (double)cvGetTickCount();

			// Capture the frame, either from the camera or video file
			if (iterations > 0) {	// Use the first frame that was already obtained during initialization.
				if (capture2) {
					frame2 = cvQueryFrame( capture2 );
					if( !frame2 )
						break;
				}
			}

			// Either save to a video file or display on the screen
			if (videoWriter) {
				// Save to the output video file
				cvWriteFrame(videoWriter, frame2);      // stabilized image
			}
			//else {
				// Display an image on the GUI
				cvShowImage( "AppendVids", frame2);	// stabilized image
			//}

			// Make sure the video runs at roughly the correct speed.
			// Add a delay that would result in roughly the desired frames per second.
			timeDiff_wholeFrameInOut = (double)cvGetTickCount() - timeStart_wholeFrameInOut;
			currentFrame_ms = (double)(timeDiff_wholeFrameInOut / (cvGetTickFrequency()*1000.0));
			delay_ms = cvRound((1000 / FPS) - currentFrame_ms);	// Factor in how much time was used to process this frame already.
			if (delay_ms < 1)
				delay_ms = 1;	// Make sure there is atleast some delay, to allow OpenCV to do its internal processing.
			c = cvWaitKey(delay_ms);	// Wait for a keypress, and let OpenCV display its GUI.

			if( (char)c == 27 )	// Check if the user hit the 'Escape' key
				break;	// Quit

			iterations++;
		}
	}

	// Free the remaining resources used when this function returns.
	return 0;
}


int main( int argc, char** argv )
{
	runAppendVids(argc, argv);

	// Free the resources used.
	if (capture1)
		cvReleaseCapture( &capture1 );
	if (capture2)
		cvReleaseCapture( &capture2 );
    cvDestroyWindow("AppendVids");
	if (videoWriter)
		cvReleaseVideoWriter( &videoWriter );

    return 0;
}
