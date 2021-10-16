#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>


using namespace std;

// 2D Matrix class
class Mat2D{
public:
	double a, b, c, d;

	Mat2D(){
		a = b = c = d = 0.0;
	}
	Mat2D(double m, double n, double o, double p){
		a = m;
		b = n;
		c = o;
		d = p;
	}

	void setMat(double m, double n, double o, double p){
		a = m;
		b = n;
		c = o;
		d = p;
		
	}
	double determinant(){
		return ((this->a*this->d)-(this->b*this->c));
	}
	void printMat(){
		cout << endl;
		cout << a << " " << b <<  endl;
		cout << c << " " << d <<  endl;
		cout << endl;
	}
	Mat2D& operator =(const Mat2D& M){
        this->a = M.a;
        this->b = M.b;
        this->c = M.c;
        this->d = M.d;

        return *this;
    }
	
};

// 2P point class

class Point2D: public Mat2D{
public:
	double x;
	double y;

	Point2D(){
		x = 0.0;
		y = 0.0;
	}
	Point2D(float a, float b){
		x = a;
		y = b;
	}
	void setxy(float a, float b){
		x = a;
		y = b;
	}
	void pointPrint(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
	friend Point2D operator *(Mat2D& e, Point2D& b){
		Point2D newP;
        newP.x =(e.a * b.x) + (e.b * b.y);
        newP.y =(e.c * b.x) + (e.d * b.y);
        return newP;
    }

};
// matrix inverse

Mat2D inverse(Mat2D& inv){
		double dt = inv.determinant();
		Mat2D newMat;
		newMat.a = inv.d/dt;
		newMat.b = -(inv.b/dt);
		newMat.c = -(inv.c/dt);
		newMat.d = inv.a/dt;

		return newMat;
	}

// Sum of x and y coordinate returned as point

Point2D sumXY(vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += val[i].x;
		sumY += val[i].y;
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of squares of the points

Point2D sumSQ(vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += pow(val[i].x, 2);
		sumY += pow(val[i].y, 2);
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of cubes of the x and y

Point2D sumCU(vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += pow(val[i].x, 3);
		sumY += pow(val[i].y, 3);
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of x*y of the points returned as double

double sumUV(vector<Point2D>& val){
	double sum = 0.0;0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += (val[i].x*val[i].y);
	}
	return sum;
}

// Sum of x*y^2 of the points returned as double

double sumUVV(vector<Point2D>& val){
	double sum = 0.0;0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += (val[i].x*(pow(val[i].y, 2)));
	}
	return sum;
}

// Sum of x^2*y of the points returned as double

double sumVUU(vector<Point2D>& val){
	double sum = 0.0;0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += ((pow(val[i].x, 2))*val[i].y);
	}
	return sum;
}
// Add points
Point2D addPoints(Point2D a, Point2D b){
	Point2D res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return res;
}
// average of the points 
Point2D average(vector<Point2D>& vecPoints){
	double sumX = 0.0;
	double sumY = 0.0;
	unsigned int N = vecPoints.size();
	for(unsigned int i=0; i<N; i++){
		sumX += vecPoints[i].x;
		sumY += vecPoints[i].y;
	}
	double avg_x = sumX/(double)N;
	double avg_y = sumY/(double)N;
	Point2D avgPT;
	avgPT.setxy(avg_x, avg_y);
	return avgPT;

}
// calculating u and v points
void uvCalculator(vector<Point2D>& vecPoints, Point2D avg, vector<Point2D>& uvpoints){
	for(unsigned int i = 0; i < vecPoints.size(); i++){
		Point2D temp;
		double a = vecPoints[i].x - avg.x;
		double b = vecPoints[i].y - avg.y;
		temp.setxy(a, b);
		uvpoints.push_back(temp);
	}
}

int main(int argc, const char * argv[]) {
    vector<Point2D> vecPoints;
  	ifstream myfile("temp.txt");

  	double x=0.0, y =0.0;
  	if(!myfile.is_open()){
  		cout << "Unable to open file"; 
  		return 0;
  	}
	while (myfile >> x >> y){
	     Point2D point;
	     point.setxy((double)x,(double)y);
         vecPoints.push_back(point);
	}
	myfile.close();
	Point2D avgPT;
    avgPT = average(vecPoints);		// average x and y
 	
    vector<Point2D> uvpoints;
    uvCalculator(vecPoints, avgPT, uvpoints); // calculating u v points

    Point2D S_2uv = sumSQ(uvpoints); // consists of two points u^2 and v ^2
    Point2D S_3uv = sumCU(uvpoints); // consists of two points u^3 and v ^3
    double S_uv = sumUV(uvpoints); // consists of sum of u.v
    double S_UVV = sumUVV(uvpoints); // consists of sum of u.v^2
    double S_VUU = sumVUU(uvpoints); // consists of sum of v.u^2

    double ap = 0.5*(S_3uv.x + S_UVV);
    double bp = 0.5*(S_3uv.y + S_VUU);

    Point2D Pab;
    Pab.setxy(ap, bp);

    unsigned int N = uvpoints.size();
    N = (double)N;

    Mat2D iMat;

    Mat2D nMat(S_2uv.x, S_uv, S_uv, S_2uv.y); 	// Initial matrix
    iMat = inverse(nMat);	// inverted matrix

    //nMat.printMat();
    //iMat.printMat();

    Point2D center;		// center of the circle
    Point2D val_uvC;		
    val_uvC = iMat*Pab;		// uc and vc
    
    center = addPoints(val_uvC, avgPT); // Actual center as we add the average


    double valSN = ((S_2uv.x + S_2uv.y)/N);

    double R = sqrt(pow(val_uvC.x, 2) + pow(val_uvC.y, 2) + valSN);
    cout << "The Number of Points are: " << N << endl;
    cout << endl;
    cout << "Circle is centered at: " << endl;
    center.pointPrint();
    cout << "\nRadius : " << endl;
    cout << R << endl;

  return 0;

}