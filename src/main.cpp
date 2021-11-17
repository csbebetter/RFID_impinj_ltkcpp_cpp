#include "RFIDHandler.h"
#include <string>
#include <sstream>


int main() {

		char *                      pReaderHostName;
		int                             rc;

		pReaderHostName = "115.156.142.223";

		/*
		* Run application, capture return value for exit status
		*/

		CMyApplication              myApp;
		myApp.m_Verbose = 1;
		//int i = 3;

		myApp.m_channelIndex = 1;
		/*Sleep(2000);*/
		rc = myApp.run(pReaderHostName);


		FILE *file_left, *file_right;
		std::string left_prefix = "/home/tom/data";

		
		file_left = fopen(left_prefix.c_str(), "w");
		//file_right = fopen(pathright.str().c_str(), "w");


		char *pattern = "%u\t%-30s\t%u\t%.3f\t%.2f\t%.2f\n"; // id epc channel frequecy phase rssi

		if (file_left != NULL) {
			int cnt = 0;
			for (auto it = myApp.leftDataVec.begin(); it != myApp.leftDataVec.end(); it++)
			{
				fprintf(file_left, pattern, ++cnt, (*it).epc, (*it).channelIndex, ((*it).channelIndex - 1)*0.25 + 920.625, (*it).phase, (*it).rssi);
			}
		}
		else {
			exit(1);
		}

	printf("INFO: Done\n");

	getchar();
}
