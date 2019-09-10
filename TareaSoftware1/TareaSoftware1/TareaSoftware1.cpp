
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//To swap arrays that use int
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//To swap arrays that use strings
void swapStr(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}


//Algorithm use to sort the diffrent places
void insertion_sort(int arreglo[], int tamano, string arregloStr[])
{
	int i = 1;
	while (i < tamano)
	{
		int j = i;
		while (j > 0)
		{
			if (arreglo[j] < arreglo[j - 1])
			{
				//Uses a function "swap" to sort by order
				swap(arreglo[j], arreglo[j - 1]);
				swapStr(arregloStr[j], arregloStr[j - 1]);
				
			}
			else
			{
				break;
			}
			--j;
		}
		++i;
	}
}



int main()
{
	//Creating variables
	ifstream readFile;
	vector<string> vecStr;
	vector<int> vecNum;
	string str;

	//Open File location
	readFile.open("D:\\Programas 3er Semestre\\results.txt");

	//If the file dosen't open
	if (!readFile)
	{
		cout << " Couldn't open file" << endl;
	}
	//If the file does open
	else
	{
		/*while (readFile >> data)
		{
			
			for (int i = 0; i <= 99; i++)
			{
				cout << data[i];
			}
		}*/
		while (!readFile.eof())
		{
			//Gets a line from the file and stores it on the vector
			getline(readFile, str);
			vecStr.push_back(str);
			stringstream ss(str);

			string word;
			int num;

			//Uses the stringstream to make another vector with just the scores of the players
			while (ss >> word)
			{
				if (ss >> num)
				{
					vecNum.push_back(num);
				}
			}
			

		}

	}

	//Creates new arrays to which convert the vectors
	int arreglo[7];
	string arregloStr[7];

	//Vector to arrays
	for (int i = 0; i < vecNum.size(); i++)
	{
		arreglo[i] = vecNum[i];
		arregloStr[i] = vecStr[i];
	}
	
	//Uses sorting algorithm
	insertion_sort(arreglo, 7, arregloStr);

	//Prints out the winners
	cout << " In First place we have " << arregloStr[6] << endl;
	cout << " In Second place we have " << arregloStr[5] << endl;
	cout << " In Third place we have " << arregloStr[4] << endl;
	
	readFile.close();

	return 0;
}
