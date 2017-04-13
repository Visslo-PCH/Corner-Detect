#include "cornerDetect.h"

using namespace cv;
using namespace std;

float cornerLineAngle(InputArray _edgeImage, InputArray _src, OutputArray _dst, int startPointX, int startPointY, int detectSize, int detectNum){

	Mat edge_img = _edgeImage.getMat();
	Mat output_img = _src.getMat();
	_dst.getMatRef() = output_img;
	int z = 0;
	int d = 0;
	vector<Point> detectPoint;

	double dx, dy;
	sPoint *aDirection = new sPoint[detectNum + 1];
	sPoint *bDirection = new sPoint[detectNum + 1];
	sLine aLine, bLine;
	/*int dx, dy;
	sPointi *aDirection = new sPointi[10];
	sPointi *bDirection = new sPointi[10];*/
	for (int k = 0 ; k < detectNum; k++){
		if (z == 0) {///코너 시작 지점//수정 요망
			aDirection[z].x = startPointX;
			aDirection[z].y = startPointY;
			bDirection[z].x = startPointX;
			bDirection[z].y = startPointY;
			dx = aDirection[z].x + detectSize;
			for (dy = aDirection[z].y - detectSize; dy <= aDirection[z].y + detectSize; dy++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dx = aDirection[z].x - detectSize;
			for (dy = aDirection[z].y - detectSize; dy <= aDirection[z].y + detectSize; dy++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = aDirection[z].y + detectSize;
			for (dx = aDirection[z].x - detectSize; dx <= aDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = aDirection[z].y - detectSize;
			for (dx = aDirection[z].x - detectSize; dx <= aDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}

			//vector<Point>::const_iterator it1;//코너 양쪽점
			//for (it1 = detectPoint.begin(); it1 != detectPoint.end(); ++it1) {
			//	circle(output_img, *it1, 5, Scalar(255, 0, 0), 2);
			//	cout << "firstPoint(" << (*it1).x << ", " << (*it1).y << ") " << endl;
			//}
			z++;
			if (d > 2) {//수정요망
			/*	float a = 0, b = 0;
				float angleD = 363, angleA = 363, angleB = 363;
				Point a, b;
				for (int i = 0; i < d; i++) {
					angleD = atan2f((float)(detectPoint[i].y - aDirection[z - 1].y), (float)(detectPoint[i].x - aDirection[z - 1].x)) * 180 / PI;
					if (angleA == 363){
						angleA = angleD;
					}else{
						a = fabs(angleA - angleD);
						if (a > 5){
							if (angleB ==363 | a > 30){
								angleB = angleD;
							}else{
								b = fabs(angleB - angleD);
								
							}
						}
					}
					
				}*/
				return 183;
			}else if (d == 2){
				aDirection[z].x = detectPoint[0].x;
				aDirection[z].y = detectPoint[0].y;
				bDirection[z].x = detectPoint[1].x;
				bDirection[z].y = detectPoint[1].y;

				detectPoint.clear();
				d = 0;
			}else{
				return 184;
			}
		}else if (z <= detectNum){//a방향 선의 측정점 찾기
			dx = aDirection[z].x + detectSize;
			for (dy = aDirection[z].y - detectSize; dy <= aDirection[z].y + detectSize; dy++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dx = aDirection[z].x - detectSize;
			for (dy = aDirection[z].y - detectSize; dy <= aDirection[z].y + detectSize; dy++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = aDirection[z].y + detectSize;
			for (dx = aDirection[z].x - detectSize; dx <= aDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = aDirection[z].y - detectSize;
			for (dx = aDirection[z].x - detectSize; dx <= aDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			//printf ("point 크기 %d \n", detectPoint.size());

			//vector<Point>::const_iterator it1;//찾은 점 표시
			//for (it1 = detectPoint.begin(); it1 != detectPoint.end(); ++it1)	{
			//	circle(output_img, *it1, 5, Scalar(0, 255, 0), 2);
			//}
			if (d > 2) {//측정점이 2개 이상
				double distDirection_o = sqrt((double)(pow((double)(aDirection[z].y - aDirection[z - 1].y) , 2) 
					+ pow((double)(aDirection[z].x - aDirection[z - 1].x) , 2))) ;

				double distDirection_d;

				float angleCalc = 362;
				float exAngle = 362;
				float preAngle = abs(atan2f((float)(aDirection[z].y - aDirection[z - 1].y) ,
					(float)(aDirection[z].x - aDirection[z - 1].x)));

				int dd = 0;
				for(k = 0; k < d ; k++){
					distDirection_d = sqrt((double)(pow((double)(detectPoint[k].y - aDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[k].x -  aDirection[z - 1].x) , 2))) ;

					if (distDirection_d > distDirection_o){
						angleCalc = abs(atan2f((float)(detectPoint[k].y -  aDirection[z].y) ,
							(float)(detectPoint[k].x -  aDirection[z].x)));

						if (exAngle == 362){
							exAngle = angleCalc;
							dd = k;
						}else{
							if (abs(exAngle - preAngle) > abs(angleCalc - preAngle)) {
								exAngle = angleCalc;
								dd = k;
							}
						}
					}
				}
				aDirection[z + 1].x = detectPoint[dd].x;
				aDirection[z + 1].y = detectPoint[dd].y;

			}else{
				if (d == 2){
					double distDirection_0, distDirection_1;
					float dist = pow(double(detectPoint[0].y - aDirection[z - 1].y),2);
					distDirection_1 = sqrt((double)(pow((double)(detectPoint[1].y - aDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[1].x - aDirection[z - 1].x) , 2))) ;
					distDirection_0 = sqrt((double)(pow((double)(detectPoint[0].y - aDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[0].x - aDirection[z - 1].x) , 2))) ;
					if (distDirection_1 > distDirection_0) {
						aDirection[z + 1].x = detectPoint[1].x;
						aDirection[z + 1].y = detectPoint[1].y;
					}else {
						aDirection[z + 1].x = detectPoint[0].x;
						aDirection[z + 1].y = detectPoint[0].y;
					}
				}
			}
			detectPoint.clear();
			d = 0;
			//b방향 선의 측정점 탐색
			dx = bDirection[z].x + detectSize;
			for (dy = bDirection[z].y - detectSize; dy <= bDirection[z].y + detectSize; dy++) {
				if (dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dx = bDirection[z].x - detectSize;
			for (dy = bDirection[z].y - detectSize; dy <= bDirection[z].y + detectSize; dy++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){
					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = bDirection[z].y + detectSize;
			for (dx = bDirection[z].x - detectSize; dx <= bDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			dy = bDirection[z].y - detectSize;
			for (dx = bDirection[z].x - detectSize; dx <= bDirection[z].x + detectSize; dx++) {
				if(dx >= (double)(edge_img.cols - detectSize * detectNum) | dy >= (double)(edge_img.rows - detectSize * detectNum))
					return 182;
				if(dx < 0 | dy < 0)
					return 182;
				int whiteDetect = edge_img.at<uchar>(dy,dx);
				if (whiteDetect == 255){

					detectPoint.push_back(Vec2i(dx, dy));
					d++;
				}
			}
			//printf ("point 크기 %d \n", detectPoint.size());

			//vector<Point>::const_iterator it2;
			//for (it2 = detectPoint.begin(); it2 != detectPoint.end(); ++it2) {
			//	circle(output_img, *it2, 5, Scalar(255, 0, 0), 2);
			//}


			if (d > 2) {//측정점이 2개 이상
				double distDirection_o = sqrt((double)(pow((double)(bDirection[z].y - bDirection[z - 1].y) , 2) 
					+ pow((double)(bDirection[z].x - bDirection[z - 1].x) , 2))) ;

				double distDirection_d;

				float angleCalc = 362;
				float exAngle = 362;
				float preAngle = abs(atan2f((float)(bDirection[z].y - bDirection[z - 1].y) ,
					(float)(bDirection[z].x - bDirection[z - 1].x)));

				int dd = 0;
				for(k = 0; k < d ; k++){
					distDirection_d = sqrt((double)(pow((double)(detectPoint[k].y - bDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[k].x -  bDirection[z - 1].x) , 2))) ;

					if (distDirection_d > distDirection_o){
						angleCalc = abs(atan2f((float)(detectPoint[k].y -  bDirection[z].y) ,
							(float)(detectPoint[k].x -  bDirection[z].x)));

						if (exAngle == 362){
							exAngle = angleCalc;
							dd = k;
						}else{
							if (abs(exAngle - preAngle) > abs(angleCalc - preAngle)) {
								exAngle = angleCalc;
								dd = k;
							}
						}
					}
				}
				bDirection[z + 1].x = detectPoint[dd].x;
				bDirection[z + 1].y = detectPoint[dd].y;

			}else{
				if (d == 2){
					double distDirection_0, distDirection_1;
					float dist = pow(double(detectPoint[0].y -  bDirection[z - 1].y),2);
					distDirection_1 = sqrt((double)(pow((double)(detectPoint[1].y - bDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[1].x -  bDirection[z - 1].x) , 2))) ;
					distDirection_0 = sqrt((double)(pow((double)(detectPoint[0].y - bDirection[z - 1].y) , 2) 
						+ pow((double)(detectPoint[0].x -  bDirection[z - 1].x) , 2))) ;
					if (distDirection_1 > distDirection_0) {
						bDirection[z + 1].x = detectPoint[1].x;
						bDirection[z + 1].y = detectPoint[1].y;
					}else {
						bDirection[z + 1].x = detectPoint[0].x;
						bDirection[z + 1].y = detectPoint[0].y;
					}
				}
			}
			detectPoint.clear();
			d = 0;
			//circle(output_img, Point(aDirection[z+1].x,aDirection[z+1].y), 5, Scalar(255, 0, 0), 2);
			//circle(output_img, Point(bDirection[z+1].x,aDirection[z+1].y), 5, Scalar(0, 255, 0), 2);
			//imshow("output",output_img);
			//waitKey(0);
			z++;


		}
	}


	double costA = ransac_line_fitting (aDirection, detectNum, aLine, 30);
	double costB = ransac_line_fitting (bDirection, detectNum, bLine, 30);


	//delete aDirection;
	//delete bDirection;
	float aAngle = (asinf(aLine.my)) *180/PI;
	float bAngle = (asinf(bLine.my)) *180/PI;
	float cornerAngle = fabs(aAngle - bAngle);
	if (cornerAngle > 80 & cornerAngle < 100){
		line(output_img, Point(aLine.sx - 500 * aLine.mx, aLine.sy - 500 * aLine.my), 
			Point(aLine.sx + 500 * aLine.mx, aLine.sy + 500 * aLine.my), Scalar(255, 0, 255), 2);
		line(output_img, Point(bLine.sx - 500 * bLine.mx, bLine.sy - 500 * bLine.my),
			Point(bLine.sx + 500 * bLine.mx, bLine.sy + 500 * bLine.my), Scalar(255, 255, 0), 2);
	}
	/*cout<<"A "<<aAngle<<endl;
	cout<<"B "<<bAngle<<endl;*/
	return cornerAngle;
}