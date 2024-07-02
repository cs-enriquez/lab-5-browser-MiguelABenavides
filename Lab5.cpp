#include <iostream>
#include <string>
using namespace std;

// complete the class below
class Stack {
	private:
		string *items; //array to hold items in stack
		int capacity;  //size of array.
		int numItems;
	public:
		// write a constructor that will have one input parameter x, with a default value of 5
			// use x as the initial value for capacity attribute
			// initialize a new array with the number of elements equal to the current capacity attribute
				// the new array will be accessed using the "items" pointer
			// be sure to set the initial number of items to zero
		Stack(int x = 5) {
			capacity = x;
			items = new string[capacity];
			numItems = 0;
		}

		// implement a "push" method to add new strings to the stack
		// be sure to update the number of items
		// if the stack is full, output a message to the console
			// increase the capacity by 5
			//  and **use dynamic allocation** to increase the capacity of the old items stack to the new capacity
		void push(string inObj) {
			if (numItems == capacity) {
				cout << "The stack is full. Increasing capacity by 5." << endl;
				capacity += 5;
				string *temp = new string[capacity];
				for (int i = 0; i < numItems; i++) {
					temp[i] = items[i];
				}
				delete[] items;
				items = temp;
			}
			items[numItems] = inObj;
			numItems++;
		}

		// implement a method to check if your stack is empty
		// returns true if empty, false if not empty
		bool empty() {
			if(numItems == 0) {
				return true;
			}
			else {
				return false;
			}
		}

		// implement a "pop" method to "remove" the top item from stack
		// this function should return the removed item item
		// dont forget to update the number of items
		// if your stack is empty, do nothing
		string pop() {
			if (numItems == 0) {
				cout << "The stack is empty. Cannot pop." << endl;
				return "";
			}
			string poppedItem = items[numItems - 1];
			numItems--;
			return poppedItem;
		}

		// implement a method getNumItems to retrieve the number of items
		//    currently in the stack
		int getNumItems() {
			return numItems;
		}
		
		// Implement a method to clear the history
		// This method should remove all urls from the history stack
		void clearHistory() {
			Stack history; // declare the 'history' stack object
			while (!history.empty()) {
				history.pop();
			}
		}

};



// Define the class BrowserHistory below
class BrowserHistory {
	private:
		// One stacks of strings and the page you are currently viewing is all that is used here
		Stack history;
		string currentUrl;

	public:
		// Implement the constructor to initialize your object
		//    with a new current page at defaultUrl
		// At this point, your history should be empty
		BrowserHistory(string defaultUrl) {
			currentUrl = defaultUrl;
		}

		// Implement the getCurrentPage method to return 
		//    the most recently visited page
		string getCurrentPage() {
			return currentUrl;
		};

		// Implement the goToPage method, which will take in a url
		//     and update the current page
		//  It should also push the previous page to the history
		//     returns nothing
		void goToPage(string inUrl) {
			history.push(currentUrl);
			currentUrl = inUrl;
		}
		
		// Implement goBack method to go to the previous page in history
		// If there is no previous page to move to, 
		//     print a message and do nothing
		void goBack() {
			if (history.empty()) {
				cout << "No previous page to go back to." << endl;
			}
			else {
				currentUrl = history.pop();
			}
		}

		// Implement method canGoBack,
		//    which determines whether there is a previous url in the history
		// Hint: your Stack class has a useful method for this!
		bool canGoBack() {
			if (!history.empty()) {
				return true;
			}
			else {
				return false;
			}
		};

		// Implement the historyLength method, which
		//    returns how many urls are in the history,
		//       not including the current page.
		//    hint: Your stack has a useful method for this!
		int historyLength() {
			return history.getNumItems();
		};


};
