//rahat choudery
#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>

class Node //represents node in a tree
{
public:
  string word;
  Node *left, *right;

  Node (string file_word)
  {
    word = file_word;
    left = NULL;
    right = NULL;
  }
};

//build tree
  void bInsert(string a, Node **t)
  {
    if ((*t) == NULL)
      {
	*t = new Node(a);
      }

    else if ((*t)->word > a)
      {
	bInsert(a, &((*t)->left)); // Insert in left subtree
      }

    else if ((*t)->word <= a)
      {
	bInsert(a, &((*t)->right));  // Insert in right subtree 
      }
  }

bool findWord(string word_b, Node *T)
{
  if (T == NULL)
    {
      return false;
    }

  else if (findWord(word_b, T->left) == true)
    {
      return true;
    }
  
  else if (T->word == word_b)
    {
      return true;
    }
  
  else
    {
      return findWord(word_b, T->right);
    }
}

//main starts here
int main()
{
  ifstream fin;
  string a;
  string b;
  char c;
  Node *T = NULL;

  //open first file
  fin.open("p5dict.txt");

  if (fin.fail())
    {
      cout << "Error!" << endl;
    }

  fin >> a;
  while (!fin.eof())
    {
      bInsert(a, &T);
      fin >> a;
    }
  fin.close();

  //open second file
  fin.open("p5suspect.txt");

  if (fin.fail())
    {
      cout << "Error!!" << endl;
    }

  fin >> b;
  while (!fin.eof())
    {
      if (findWord(b, T) == true)
	{
	  //	  cout << b << " was found!" << endl;
	  //	  cout << endl;
	}

      else if (findWord(b, T) == false)
	{
	  cout << b << " was not found in the dictionary! Would you like to add it to the dictionary? Y/N" << endl;
	  cin >> c;
	  if (c == 'Y' || c == 'y')
	    {
	      bInsert(b, &T);
	      cout << b << " has been inserted to the dictionary!" << endl;
	      cout << endl;
	    }

	  else if (c == 'N' || c == 'n')
	    {
	      cout << b << " is misspelled and was not added to dictionary." << endl;
	      cout << endl;
	    }
	}
      fin >> b;
    } //end of while loop
} //end of main
