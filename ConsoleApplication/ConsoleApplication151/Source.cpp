#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
	char a[]="Commander_Name VARCHAR(12), Profession VARCHAR(12), Commander_HP VARCHAR(12),\
	Action_Status VARCHAR(12), Map_image VARCHAR(12), Y - axis_coordinate VARCHAR\
	(12), X_coordinate VARCHAR(12), Equipped_with_weapons VARCHAR(12),\
	Auxiliary_magic_effect VARCHAR(12), Equipment_accessories VARCHAR(12),\
	Equipment_and_armor VARCHAR(12), Mercenary_belongs VARCHAR(12),\
	Mercenary_arms VARCHAR(12), Mercenary_HP VARCHAR(12),\
	Mercenary_action_status VARCHAR(12), Mercenary VARCHAR(12),\
	Force_serial_number VARCHAR(12), The_mercenary_Y_axis_coordinates VARCHAR(12),\
	The_mercenary_X_axis_coordinates VARCHAR(12), Instruction VARCHAR(12),\
	Belongs_forces VARCHAR(12), Commander_of_experience VARCHAR(12),\
	Commander_Level VARCHAR(12), Max_MP VARCHAR(12), MP VARCHAR(12),\
	Defense VARCHAR(12), ATK VARCHAR(12), Moving_force VARCHAR(12), \
	Command_range VARCHAR(12), Defense_correction VARCHAR(12),\
	Attack_modifier VARCHAR(12), Magic_16 - 23 VARCHAR(12),\
	Occupational_magic_defense VARCHAR(12), Magic_1 - 7 VARCHAR(12), Magic_8 -\
	15 VARCHAR(12), Summon_MP VARCHAR(12), Charm_of_before_they VARCHAR(12),\
	Commander_Portrait VARCHAR(12)";
	strupr(a);
	cout<<a<<endl;


	ofstream fout("C:\\c++\\epbgit\\test1\\Win32\\Release\\temp.txt", ios::out | ios::binary); 
    if(!fout) { 
        cout << "無法讀取檔案" << endl; 
        return 1; 
    } 
	fout<<a;
    //int arr[5] = {1, 2, 3, 4, 5}; 
    //fout.write((char*) arr, sizeof(arr)); 
    fout.close(); 
	
	system("pause");

	return 0;
}