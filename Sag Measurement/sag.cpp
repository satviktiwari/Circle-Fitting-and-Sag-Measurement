#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter number of points:" << endl;
    cin >> n;
    
    double val = 0;
    vector<double>xposition(n, 0);

    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the X-Position: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        xposition[i] = val;
    }

    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Pixel-Position: ";
    vector<double>pixposition(n, 0);
    for(int i = 0; i < n; i++){
        cin >> val;
        pixposition[i] = val;
    }

    vector<double>normalSub(n, 0);
    for(int i = 0; i < n; i++){
        //cin >> val;
        normalSub[i] = pixposition[i]-230;
    }

    vector<double>scalingFactor(n, 0);
    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Scaling-Factor: ";
    cout << endl;
    for(int i = 0; i < n; i++){
        cin >> val;
        scalingFactor[i] = val;
    }

    vector<double>heightIntegration(n, 0);
    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Height Integration Value: ";
    cout << endl;
    for(int i = 0; i < n; i++){
        cin >> val;
        heightIntegration[i] = val;
    }
    
    vector<double>sag(n, 0);
    for(int i = 0 ; i < n; i++){
        if(heightIntegration[i] == 0){
            sag[i] = 0;
        }
        else{
            sag[i] = abs(normalSub[i])*abs(scalingFactor[i])/abs(heightIntegration[i]);
                if(scalingFactor[i] < 0){
                sag[i] = -sag[i];
            }
        }
    }

    cout << "<<====================================================================================================>>" << endl;
    cout << "<<=========================================--OUTPUT--SCREEN--=========================================>>" << endl;
    cout << "<<====================================================================================================>>" << endl;
    cout << "The sag measurement is: " << endl;
    for(int i = 0; i < n; i++){
        if(sag[i] >= 0){
            cout << "Sag Measurement at point " << xposition[i] << " with pixel position "<< pixposition[i] << " is " << sag[i] << " mm." << endl;
        }
        else{
            sag[i] *= -1;
            cout << "Sag Measurement at point " << xposition[i] << " with pixel position "<< pixposition[i] << " is " << sag[i] << " mm in negative direction." << endl;
        }
    }
    cout << endl;
    cout << "<<====================================================================================================>>" << endl;
    cout << "<<=======================================--OUTPUT--SCREEN--END--======================================>>" << endl;
    cout << "<<====================================================================================================>>" << endl;
    return 0;
}
