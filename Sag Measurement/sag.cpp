#include<bits/stdc++.h>
using namespace std;

int main(){
    int var = 0;
    vector<int>xposition(61, 0);
    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the X-Position: ";
    for(int i = 0; i < 61; i++){
        cin >> var;
        xposition[i] = var;
    }

    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Pixel-Position: ";
    int pixpos = 0;
    vector<int>pixposition(61, 0);
    for(int i = 0; i < 61; i++){
        cin >> pixpos;
        pixposition[i] = pixpos;
    }

    vector<double>scalingFactor(61, 0);
    double val = 0;
    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Scaling-Factor: ";
    cout << endl;
    for(int i = 0; i < 61; i++){
        cin >> val;
        scalingFactor[i] = abs(val);
    }
    // cout << "The scaling factor is: ";
    // for(int i = 0; i < 61; i++){
    //     cout << scalingFactor[i] << " ";
    // }
    // cout << endl;
    vector<double>heightIntegration(61, 0);
    double pos = 0;
    cout << "<<====================================================================================================>>" << endl;
    cout << "Enter the Height Integration Value: ";
    cout << endl;
    for(int i = 0; i < 61; i++){
        cin >> pos;
        heightIntegration[i] = abs(pos);
    }
    
    // for(int i = 1; i < 61; i++){
    //     heightIntegration[i] = heightIntegration[i] - heightIntegration[i-1];
    // }

    // cout << "<<====================================================================================================>>" << endl;
    // cout << "The position is: ";
    // for(int i = 0; i < 61; i++){
    //     cout << heightIntegration[i] << " ";
    // }
    // cout << endl;
    vector<double>sag(61, 0);
    for(int i = 0 ; i < 61; i++){
        if(heightIntegration[i] == 0 || scalingFactor[i] == 0){
            sag[i] = 0;
        }
        else{
            sag[i] = heightIntegration[i]*cosh(scalingFactor[i]/heightIntegration[i]);
        }
        //cout << sag[i] << " ";
    }
    //cout << endl;
    cout << "<<====================================================================================================>>" << endl;
    cout << "<<=========================================--OUTPUT--SCREEN--=========================================>>" << endl;
    cout << "<<====================================================================================================>>" << endl;
    cout << "The sag measurement is: " << endl;
    for(int i = 0; i < 61; i++){
        cout << "Sag Measurement at point " << xposition[i] << " with pixel position "<< pixposition[i] << " is " << sag[i] << " degrees." << endl;
    }
    cout << endl;
    cout << "<<====================================================================================================>>" << endl;
    cout << "<<=======================================--OUTPUT--SCREEN--END--======================================>>" << endl;
    cout << "<<====================================================================================================>>" << endl;
    return 0;
}