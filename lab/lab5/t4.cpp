#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <sstream>
#include<fstream>
using namespace std;
// 1. Define a class/struct  Student  with  name  (string) and  score  (int).
//2. Write a function  vector<Student> loadData(string filename) .
//It opens the file.
//Reads line by line.Each line format is  Name, Score(e.g., John, 90).
//Parses the string to separate the name and the integer score.
//Returns a vector of Student objects.
//3. Main Function :
//Create a file named  data.txt  with the input data provided via  cin(read until EOF or
//	specific marker).Note : In a real scenario, the file exists, but for this lab, write the input to a
//	file first, then call your loadData function.
//	Call  loadData("data.txt") .
//	Calculate and print the average score(printed to 1 decimal place).
// Find and print the name of the student with the highest score
class Student
{
	
public:
	string name;
	int score;
	static vector<Student> loadData(string filename)
	{
		vector<Student> arr;
		ifstream in(filename);
	    string str;
		if (!in.is_open())//Use  str.find(',')  to locate the comma.
			//Use  str.substr(...)  to extract parts.
			//Use  std::stoi(...)  to convert the score string to an integer
		{
			cerr << "error" << endl;
			return arr;
		}
		while (getline(in, str))
		{
			Student stu;
			size_t comma_position = str.find(',');
			stu.name = str.substr(0, comma_position);
			stu.score = stoi(str.substr(comma_position + 1));
			arr.push_back(stu);
		}
		in.close();
		return arr;
	}
};
	
	int main()
	{
		ofstream out("data.txt");
		string input_line;
		while (getline(cin, input_line))
		{
			out << input_line << endl;
		}
		out.close();
		vector<Student> k = Student::loadData("data.txt");
		double sum = 0.0;
		double max = k[0].score;
		string best_name = k[0].name;
		for (auto i : k)
		{
			if (i.score > max)
			{
				max = i.score;
				best_name = i.name;
			}
			sum += i.score;
		}
		double average = sum / k.size();
		cout << fixed << setprecision(1);
		cout << "Average: " << average << endl;
		cout << "Best: " << best_name << endl;
		return 0;
	}