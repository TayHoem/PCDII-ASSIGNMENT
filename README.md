# PCDII-ASSIGNMENT
PCDII ASSIGNMENT SEM3 G8 
This is the programming assignment that I, Tay Tem Hoe doing with my group mates using the C language. This assignment is to develop a system that can be used to support the operation of a small MLM company. This system that we build provides support to a grocery company. The data of the system that we store is using binary and text files. The part I doing is the Member part. The Member part got five functions that are Sign Up, Modify Personal Data, Search Member Bonus, Search Order History function, and Eliminate member.

Sign Up 
The Customers of “The Daily Market” can create a MEMBER through this function. To create a MEMBER the customers need to create a particular member ID that is no more than 9 characters and a password that is no more than 10 characters by themselves. If the member Id and password are more than the size that is set or if the member Id either the password is already or both already exist in the file it will request the customers to key in again.
Moreover, the customers also need to key in some personal details. That is name, gender(Male  or Female ), phone number, and email. Also, the system will request the customers to key in again if the phone number and email have existed. 
Other than that, the customer also needs to choose the MEMBER type such as Normal, Bronze, Silver, and Golden, and the period of membership such as 1, 2, or 3 years. 
Before MEMBER creation, the system will ask the customer to confirm whether to become a member or not. 
If yes, all data will be stored in the Member file, and show out the table of the member.
If not, the system will stop and cancel the sign-up function and back to the main MEMBER menu.

The modify function
In modify function, the system will be based on the member ID that customers key in when login, the system will find out the list of data for the member ID and show the customers for the member ID. At the same time, the system will display the MENU of modifications that can let the customers choose what data they want to change. The data they can change is (1) name, (2) phone number,(3) email, (4) member type, and period of membership. Based on the option chosen by the customers, customers can change each data one by one. After, confirm message is displayed to the customer to ask them to confirm the change or not. If yes, display the change message if no then display no data be changed. The data will store back when the customer (5) end modifies.

The Sreach Order History
In the SEARCH function, the system will be based on the member ID that the customers key in when login, the system will find out the order history of the customer that order made by the customer at the SALES Module, add order function by using the customer name. If that is order history found, then the system will display the all order history that scans from the Order file. If not the system will display the message that tells the customer no order history was found, please make an order at our “The Daily Market” grocery order page first.

Display Bonus
Based on the member ID that customers key in when login, the system will find out the list of data for the member ID and check what is the member type of the customer. For example, if the Member Type is Bronze then it will display the Bonus of Bronze Membership like below. Also, it will display the BONUS of Normal, Sliver, and Golden if the member type matches. After the display BONUS, it will jump back to the main member menu. 

Eliminate member
Customers can cancel their membership in the Daily Market by using the member delete function. To cancel the membership, the customer must key in their member ID and password, so the system can find out the data of the member based on this both particular data. Before deleting, the system will display a message to ask the customer sure to delete. If yes then the system will delete the all data of the customer and will return 75% of the member fee to the customer in 3 working days. If no, the delete function will stop and return to the main menu of the MEMBER module.


