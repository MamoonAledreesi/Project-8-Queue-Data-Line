#pragma once

#include<iostream>
#include<queue>
#include "clsDate.h"
using namespace std;

////////Another way of sulotuion
//Mamoon Aledreesi
class clsQueueDataLine2
{
private:
	string _Prefix;
	short _WaittingTime = 0;

	class Ticket
	{
	public:
		string _Prefix;
		short _WaittingTime = 0;
		short _WaittingClients = 0;
		short _ServingClients = 0;
		short _IssueTicket = 0;
		queue <int> _PushTickts;
		queue <int> _PopTickts;
		int _TotalTickts = 1;

	};
	Ticket NewTicket;

	void _PrintTicket()
	{

		cout << "\n\t\t---------------------------";
		cout << "\n\t\t\t\t " << _Prefix << NewTicket._PushTickts.front();
		cout << "\n\t\t" << clsDate::GetSystemDateTimeString();
		cout << "\n\t\tWaitting Clients: " << NewTicket._WaittingClients;
		cout << "\n\t\tWaitting Time: " << NewTicket._WaittingClients * NewTicket._WaittingTime;
		NewTicket._WaittingClients = NewTicket._WaittingClients + 1;

		cout << "\n\t\t---------------------------\n";
	}
public:



	clsQueueDataLine2(string Prefix, short WaittingTime)
	{
		_Prefix = Prefix;
		_WaittingTime = WaittingTime;
	}



	void IssueTicket()
	{
		NewTicket. _PushTickts.push(NewTicket._TotalTickts++);
		NewTicket._IssueTicket++;
	}

	void PrintInfo()
	{
		cout << "\n\n\t\t\t-----------------------\n";
		cout << "\t\t\t\tQueue Info";
		cout << "\n\n\t\t\t-----------------------\n";

		cout << "\t\t\tPrefix = " << _Prefix;
		cout << "\n\t\t\tTotal Tickts     = " << NewTicket._IssueTicket;
		cout << "\n\t\t\tServing Clients  = " << NewTicket._ServingClients;
		cout << "\n\t\t\tWaitting Clients = " << NewTicket._PushTickts.size();
		cout << "\n\t\t\t----------------------------------\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\n\t Tickets: ";

		while (!NewTicket._PushTickts.empty())
		{
			NewTicket._PopTickts.push(NewTicket._PushTickts.front());
			cout << _Prefix << NewTicket._PushTickts.front() << " " << "<--" << " ";

			NewTicket._PushTickts.pop();
		}
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\n\t Tickets: ";

		while (!NewTicket._PopTickts.empty())
		{

			NewTicket._PushTickts.push(NewTicket._PopTickts.front());
			cout << _Prefix << NewTicket._PopTickts.front() << " " << "<--" << " ";
			NewTicket._PopTickts.pop();
		}
	}


	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t--Tickets--";
		while (!NewTicket._PushTickts.empty())
		{
			NewTicket._PopTickts.push(NewTicket._PushTickts.front());
			_PrintTicket();
			NewTicket._PushTickts.pop();
		}
	}
	void ServeNextClients()
	{
		NewTicket._PushTickts = NewTicket._PopTickts;

		while (!NewTicket._PushTickts.empty())
		{

			NewTicket._PushTickts.pop();
			NewTicket._ServingClients = NewTicket._ServingClients + 1;
			break;
		}

	}
};



