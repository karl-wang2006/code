#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <sstream>
using namespace std;
vector<string> get_msg()
{
	vector<string> msg;
	string line,str;
	getline(cin, line);
	istringstream line_stream(line);//transfer line into line_stream that can be read
	while (line_stream >> str)
	{
		msg.push_back(str);
	}
	return msg;
}

class Batchlogger
{
public:
	int capacity;
	vector<string> buffer;
	string name;
	Batchlogger(string str,int num)
	{
		name = str;
		capacity = num;
		cout << "Logger" << " " << name << " " << "initialized." << endl;
	}
	void log(vector<string> msg)//Adds  msg  to the  buffer .
		                //Check: If the  buffer  size reaches the  capacity :
	                    //Call  flush()
	{
		int num = msg.size();
		int time = num / capacity;
		for (int i = 0; i < time; i++)
		{
			flush();
		}
	}
	void flush()//Prints:  [name] flushing:   followed by all messages in the buffer separated by spaces.
		        //Clears the buffer after printing
	{
		cout << name << " flushing:";
		for (int i=0 ; i< capacity ;i++)
		{
			cout << buffer.front() <<" ";//print the first string
			buffer.erase(buffer.begin());//delete the first string
		}
		cout << endl;
	}
	~Batchlogger() //Logic: If the buffer is not empty, it must output the remaining messages.
		           //Prints : [name] closing : followed by the remaining messages separated by spaces.
		           //(If the buffer is empty, the destructor does nothing visible).
	{
		int f = 1;
		while (buffer.size() != 0)
		{
			
			if(f) 
				cout << name << " closing:";
			f = 0;
			cout << buffer.front() << " ";//print the first string
			buffer.erase(buffer.begin());//delete the first string
		}
	}  

};
int main()
{
	string buffer_name,msg;
	int capacity,count;
	vector<string> buffer_msg;
	cin >> buffer_name >> capacity >> count;
    cin.ignore();//clear '\n'
	buffer_msg = get_msg();
	Batchlogger a(buffer_name,capacity);
	a.buffer = buffer_msg;
	a.log(buffer_msg);
	return 0;
}