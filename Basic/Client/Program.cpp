// Copyright (c) Traeger Industry Components GmbH. All Rights Reserved.



using namespace System;
using namespace Opc::UaFx::Client;
using namespace System::Threading;
using namespace std;

#include <iostream>
#include <string>
#include <cstring>


std::string strName;
double dPosition;
int nMode;
bool bStatus;
double dTemp;
double dValue;
int nDevChange;

void CommunicateWithServer(OpcClient% client);
void ChooseDevice();
//array<String^>^ args
/// <summary>
/// This sample demonstrates how to implement a primitive OPC UA client.
/// </summary>
int main(int argc, char* argv[])
{
    //// If the server domain name does not match localhost just replace it
    //// e.g. with the IP address or name of the server machine.

    #pragma region 1st Way : Use the OpcClient class.
    {
        // The OpcClient class interacts with one OPC UA server. While this class
        // provides session based access to the different OPC UA services of the
        // server, it does not implement a main loop.
        OpcClient client(L"opc.tcp://localhost:4880/");
        client.Connect();       
        cout << "Connected to Server" << endl;
        while (true)
        {
            ChooseDevice();
            CommunicateWithServer(client);
            Thread::Sleep(1000);
        }       
        client.Disconnect();
    }
    #pragma endregion
}


void CommunicateWithServer(OpcClient %client)
{    
    /*Write Data*/
    switch (nDevChange)
    {
    case 1:
    {
       /* int s = strName.length();
        client.WriteNode(L"ns=2;s=Motor1/NameLen", s);
        for (int i = 0; i < strName.length() ; i++)
        {
            nConvert[i] = strName[i];
            string str1 = "ns=2;s=Motor1/nName" + std::to_string(i);
            String^ str2 = gcnew String(str1.c_str());
            client.WriteNode(str2, str2);
            
        }*/
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=2;s=Motor1/Name", strNameConv);
        client.WriteNode(L"ns=2;s=Motor1/Position", dPosition);
        client.WriteNode(L"ns=2;s=Motor1/Mode", nMode);
        client.WriteNode(L"ns=2;s=Motor1/Status", bStatus);
        client.WriteNode(L"ns=2;s=Motor1/Temperature", dTemp);
        break;
    }
    case 2:
    {
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=2;s=Motor2/Name", strNameConv);
        client.WriteNode(L"ns=2;s=Motor2/Position", dPosition);
        client.WriteNode(L"ns=2;s=Motor2/Mode", nMode);
        client.WriteNode(L"ns=2;s=Motor2/Status", bStatus);
        client.WriteNode(L"ns=2;s=Motor2/Temperature", dTemp);
        break;
    }
   
    case 3:
    {
        
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=3;s=Sensor1/Name", strNameConv);
        client.WriteNode(L"ns=3;s=Sensor1/Status", bStatus);
        client.WriteNode(L"ns=3;s=Sensor1/MeasValue", dValue);
        break;
    }
    case 4:
    {
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=3;s=Sensor2/Name", strNameConv);
        client.WriteNode(L"ns=3;s=Sensor2/Status", bStatus);
        client.WriteNode(L"ns=3;s=Sensor2/MeasValue", dValue);
        break;
    }
    case 5:
    {
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=4;s=Robot1/Name", strNameConv);
        client.WriteNode(L"ns=4;s=Robot1/Position", dPosition);
        client.WriteNode(L"ns=4;s=Robot1/Mode", nMode);
        client.WriteNode(L"ns=4;s=Robot1/Status", bStatus);
        client.WriteNode(L"ns=4;s=Robot1/Temperature", dTemp);
        break;
    }
    case 6:
    {
        String^ strNameConv = gcnew String(strName.c_str());
        client.WriteNode(L"ns=4;s=Robot2/Name", strNameConv);
        client.WriteNode(L"ns=4;s=Robot2/Position", dPosition);
        client.WriteNode(L"ns=4;s=Robot2/Mode", nMode);
        client.WriteNode(L"ns=4;s=Robot2/Status", bStatus);
        client.WriteNode(L"ns=4;s=Robot2/Temperature", dTemp);
        break;
    }
    default:
    {
        break;
    }

    }
    
}
void ChooseDevice()
{
    cout << "1: Motor 1       " << "2: Motor 2       " << endl;
    cout << "3: Sensor 1      " << "4: Sensor 2      " << endl;
    cout << "5: Robot 1       " << "6: Robot 2       " << endl;
    cout << "Choose a specific device below to change data: ";
    cin >> nDevChange;
    cout << "Device Name: ";
    cin >> strName;

    if (nDevChange == 3 || nDevChange == 4)
    {
        // Sensor

        cout << "Measurement Value: ";
        cin >> dValue;

        cout << "Status: ";
        cin >> bStatus;

    }
    else
    {
        // Motor and Robot

        cout << "Position: ";
        cin >> dPosition;

        cout << "Mode: ";
        cin >> nMode;

        cout << "Temperature: ";
        cin >> dTemp;

        cout << "Status: ";
        cin >> bStatus;       
    }
}


//char val[10];
//fgets(val, sizeof(val) + 1, stdin);
//dValue = atof(val);
//
//char stt[1];
//fgets(stt, sizeof(stt) + 1, stdin);
//bStatus = stt;
//
//char pos[10];
//fgets(pos, sizeof(pos) + 1, stdin);
//dPosition = atof(pos);
//
//char m[5];
//fgets(m, sizeof(m) + 1, stdin);
//nMode = atoi(m);
//
//char temp[10];
//fgets(temp, sizeof(temp) + 1, stdin);
//dTemp = atof(temp);
//
//char stt[1];
//fgets(stt, sizeof(stt) + 1, stdin);
//bStatus = stt;