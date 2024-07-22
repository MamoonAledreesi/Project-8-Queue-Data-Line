#pragma once
#include<iostream>
#include<queue>
#include "clsDate.h"
using namespace std;

////////Another way of sulotuion
//Mamoon Aledreesi

class clsQueueDataLine
{
private:
	string _Prefix;
	short _WaittingTime=0;
	short _WaittingClients=0;
	short _ServingClients=0;
	short _IssueTicket=0;
	queue <int> _PushTickts;
	queue <int> _PopTickts;
	int _TotalTickts = 1;

	void _PrintTicket()
	{

		cout << "\n\t\t---------------------------";
		cout << "\n\t\t\t\t " << _Prefix << _PushTickts.front();
		cout << "\n\t\t" << clsDate::GetSystemDateTimeString();
		cout << "\n\t\tWaitting Clients: " << _WaittingClients;
		cout << "\n\t\tWaitting Time: " << _WaittingClients * _WaittingTime;
		_WaittingClients = _WaittingClients + 1;

		cout << "\n\t\t---------------------------\n";
	}
public:



	clsQueueDataLine(string Prefix, short WaittingTime)
	{
		_Prefix = Prefix;
		_WaittingTime = WaittingTime;
	}

	

	void IssueTicket()
	{
		_PushTickts.push(_TotalTickts++);
		_IssueTicket++;
	}

	void PrintInfo()
	{
		cout << "\n\n\t\t\t-----------------------\n";
		cout << "\t\t\t\tQueue Info";
		cout << "\n\n\t\t\t-----------------------\n";

		cout << "\t\t\tPrefix = " << _Prefix;
		cout << "\n\t\t\tTotal Tickts     = " << _IssueTicket;
		cout << "\n\t\t\tServing Clients  = " <<_ServingClients ;
		cout << "\n\t\t\tWaitting Clients = " << _PushTickts.size();
		cout << "\n\t\t\t----------------------------------\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\n\t Tickets: ";

		while (!_PushTickts.empty())
		{
			_PopTickts.push(_PushTickts.front());
			cout << _Prefix << _PushTickts.front() << " " << "<--" << " ";
			
			_PushTickts.pop();
		}
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\n\t Tickets: ";

		while (!_PopTickts.empty())
		{

			_PushTickts.push(_PopTickts.front());
			cout << _Prefix << _PopTickts.front() << " " << "<--" << " ";
			_PopTickts.pop();
		}
	}

	
	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t--Tickets--";
		while (!_PushTickts.empty())
		{
			_PopTickts.push(_PushTickts.front());
			_PrintTicket();
			_PushTickts.pop();
		}
	}
	void ServeNextClients()
	{
		_PushTickts = _PopTickts;
		
		while (!_PushTickts.empty())
		{
			 
			_PushTickts.pop();
			_ServingClients = _ServingClients + 1;
			break;
		}
		
	}
};



