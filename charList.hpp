/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	ASSGN5: Char Linked List
*/
class CharList{
	public:
		CharList();

		~CharList();

		void appendNode(char);
		void insertNode(char);
		void deleteNode(char);
		void displayList() const;

	private:
		// Define struct for linking list elements
		struct ListNode{
				char value;
				struct ListNode *next;
		};
		// Define head pointer
		ListNode *head;
};
