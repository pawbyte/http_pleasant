

#include <iostream>
#include <string>
#define HTTP_IMPLEMENTATION
#include "http_pleasant.h"
#include <cmath>
#include <stdio.h>

int main( int argc, char** argv )
{
	(void) argc, argv;

	system("pause");
	std::string download_url = "http://github.com/"; //Replace Google.com with a file located ONLY ON A HTTP(NON-SECURE SITE), SSL IS NOT YET SUPPORTED
	http_t* request = http_get(download_url.c_str() , NULL );
	int start_response_size = (int) request->response_size;
	if( !request )
	{
		printf( "Invalid request.\n" );
		system("pause");
		return 1;
	}
    std::cout << "Downloading from ( " +download_url+")" << std::endl;
	http_status_t status = HTTP_STATUS_PENDING;
	int prev_size = -1;
	int headerSizeTotal = 0;
	int prev_headerSizeTotal = 0;
	while( status == HTTP_STATUS_PENDING )
	{
		status = http_process( request );
		headerSizeTotal = request->header_size;
		if( prev_size != (int) request->header_size && headerSizeTotal !=0 )
		{
		    std::cout << "\r" << floor( (float)request->response_size /1028.f )<< "/" << floor( (float)headerSizeTotal /1028.f )<< " bytes || " << 100.f * ( (float)request->response_size / (float)headerSizeTotal ) << "%";

			prev_size = (int) request->response_size;
			prev_headerSizeTotal = headerSizeTotal;
		}
	}

	if( status == HTTP_STATUS_FAILED )
	{
		printf( "HTTP request failed (%d): %s.\n", request->status_code, request->reason_phrase );
		http_release( request );
		system("pause");
		return 1;
	}


	printf( "\nContent type: %s\n\n%s\n", request->content_type, (char const*)request->reason_phrase );


	FILE * pFile;
    pFile = fopen ("test.zip", "wb");
    fwrite (request->response_data , 1, (int) request->response_size, pFile);
    fclose (pFile);


    http_release( request );
	system("pause");
	return 0;
	}
