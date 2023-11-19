#include <iostream>
#include <string>
#include <algorithm>  
#include<windows.h>
#include<vector>
#include"mmsystem.h"
#include<conio.h>
#include<queue>
using namespace std;

struct node {
    string data;
    struct node*next;
    struct node*prev;
};

string temp;
struct node*head = NULL;
struct node*current_node = NULL;


void insert() {
    cout << "Enter Music Name:" << endl;
    cin.ignore();
    getline(cin, temp);
    struct node* new_node = new node();
    new_node->data = temp;
    if(head == NULL) {
        new_node->next = new_node->prev = new_node;
        head = current_node = new_node;
        return;
    }
    struct node*last = head->prev;
    new_node->prev = last;
    last->next = new_node;
    new_node->next = head;
    head->prev = new_node;
}

void Delete_element() {
    if(head == NULL) {
        cout << "No Music is there to delete!" << endl;
        return;
    }
    cout << "Enter Music Name to delete:" << endl;
    cin.ignore();
    getline(cin, temp);
    cout << endl;
    struct node*ptr = head;
    do { 
        if(ptr->next == ptr && ptr->data == temp) {
            cout << "One file deleted! Playlist is Empty Now!" << endl;
            head = NULL;
            delete ptr;
            return;
        }
        else if(ptr->data == temp) {
            struct node*prev = ptr->prev;
            struct node*next = ptr->next;
            prev->next = next;
            next->prev = prev;
            head = next;
            delete ptr;
            cout << "Music deleted!" << endl;
            return;
        }
        ptr = ptr->next;
    } while(ptr != head);
    cout << "No Music file is there!" << endl;
}
void show() {
    if(head == NULL) {
        cout << "Playlist is Empty!" << endl;
        return;
    }
    struct node*show_ptr = head;
    cout << endl;
    int i = 1;
    cout << "Displaying Playlist :" << endl;
    do {
        cout << "Song " << i << " : " << show_ptr->data << endl;
        i++;
        show_ptr = show_ptr->next;
    } while(show_ptr != head);
}

void next_node() {
    if(current_node == NULL) {
        cout << "No songs in Playlist!" << endl;
        }
    else {
        current_node = current_node->next;
        cout << "Playing Next Song : " << current_node->data << endl;
        PlaySound(TEXT("alag-asman.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        getch();
        PlaySound(0,0,0);
    }
}

void prev_node() {
    if(current_node == NULL) {
        cout << "No songs in Playlist!" << endl;
    }
    else {
    	
        current_node = current_node->prev;
        cout << "Playing Previous Song : " << current_node->data << endl;
        PlaySound(TEXT("country.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        getch();
        PlaySound(0,0,0);
    }

}

void first_node() {
    if(head == NULL) {
        cout << "Playlist is Empty!" << endl;
    }
    else {
        cout << "Playing First Music : " << head->data << endl;
        PlaySound(TEXT("very.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        getch();
        PlaySound(0,0,0);
    }
}

void last_node() {
    if(head == NULL) {
        cout << "Playlist is Empty!" << endl;
    }
    else {
    	PlaySound(TEXT("sms.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        cout << "Playing Last Music : " << head->prev->data << endl;
        getch();
        PlaySound(0,0,0);

    }
}

void search() {
	int counter=0;
    if(head == NULL) {
        cout << "No music is there to be searched!" << endl;
        return;
    }
    cout << "Enter Music Name to search:" << endl;
    cin.ignore();
    getline(cin, temp);
    cout << endl;
    struct node*ptr = head;
    do {
    	counter++;
        if(ptr->data == temp) {
            cout << "Music Found AT INDEX "<<counter<< endl;
            return;
        }
        ptr = ptr->next;
    } while(ptr != head);
    cout << "Music Not Found!" << endl;
}

void shuffle() {
    if(head == NULL) {
        cout << "Playlist is Empty!" << endl;
        return;
    }
    vector<string> songs;
    struct node*ptr = head;
    do {
        songs.push_back(ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
    random_shuffle(songs.begin(), songs.end());
    struct node*current = head;
    for(int i = 0; i < songs.size(); i++) {
        current->data = songs[i];
        current = current->next;
    }
    cout << "Playlist Shuffled Successfully!" << endl;
}

void playPlayList() {
    cout << "Select song for which you want to see the lyrics:" << endl;
    cout << "1. Gerua" << endl;
    cout << "2. BLINDING LIGHTS" << endl;
    cout << "3. BARISHEIN" << endl;
    cout << "4. TUM HI HO" << endl;
    cout << "5. TUM SE HI" << endl;
    cout << "6. SUKOON" << endl;
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
        	system("Color 5");
        	PlaySound(TEXT("Gerua.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout << "" << endl;
            cout << "Chorus: "<<endl;
            cout<< "Lyrics of Gerua:" << endl;
            cout<<"\nDhoop se nikhal ke\nChaaon se phisal ke\nHum mile jahan par\nLamha tham gaya\n";
            Sleep(100);
			cout<< "\nAasmaan pighal ke\nSheeshe mein dhalke\nJam gaya to tera chehra ban gaya\n";
			Sleep(100);
			cout<<"\nDuniya bhulake tumse mila hun\nNikli hai dilse ye duaa\nRang de tu mohe gerua\nRanjhe ki dil se hai duaa\nRang de tu mohe gerua\n";
			Sleep(100);
            cout<<"\nHaan nikli hai dil se ye dua\nHo rang de to mohe gerua\n";
            Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
        case 2:
        	system("Color 9");
        	PlaySound(TEXT("Blinding-Lights.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout << "Lyrics of Blinding lights:" << endl;
            cout << "Chorus: "<<endl;
            cout<<"\nYeah\nI've been tryna call\nI've been on my own for long enough\nMaybe you can show me how to love, maybe\nI'm going through withdrawals\nYou don't even have to do too much\nYou can turn me on with just a touch, babyn\n";
            Sleep(100);
			cout<< "\nI look around and\nSin City's cold and empty (oh)\nNo one's around to judge me (oh)\nI can't see clearly when you're gone\n";
			Sleep(100);
			cout<<"\nI said, ooh, I'm blinded by the lights\nNo, I can't sleep until I feel your touch\nI said, ooh, I'm drowning in the night\nOh, when I'm like this, you're the one I trust\n(Hey, hey, hey)\n";
			Sleep(100);
            cout<<"\nI'm running out of time\n'Cause I can see the sun light up the sky\nSo I hit the road in overdrive, baby, oh\n";
            Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
        case 3:
        	system("Color 6");
        	PlaySound(TEXT("Baarishien.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout<< "Lyrics of the Baarishein:" << endl;
            cout<<"\nHaule Se, Dheeme Se,\nMujh Ko Baahon Mai Bhar Lo Na Tum\nNaram Si, Sanson Mai,\nMujhko Aahon Mai Bhar Lo Na Tum\n";
            Sleep(100);
			cout<< "\nSun Zara Mere Paas Aa\nAb Beithe Hain Hum Bhi Yaha\nDil Ke Darmiyan\nBaarishein Hain Barishein Hain\n";
			Sleep(100);
			cout<<"\nTeri Hi Baaton Pe Maine\nSaja Li Hai Duniya Yahan\nDil Ke Darmiyan\nBaarishein Hain Baarishein\n";
			Sleep(100);
            cout<<"\nAb Tu Aati Hai Bulati Hai,\nBistar Se Youn Girati Hai\nKe So Un Mai\nBaahon Mai Bus Teri";
            Sleep(100);
            cout<<"\n";
            Sleep(100);
            cout<<"\nJab Baarishein Barasti Hain\nPagal Jaise Thirakti Hain\nTum Jaisi Ho\nBus Wesi Hi Raho\n";
            Sleep(100);
			cout<<"\nAb Tere Bina Yahan Meri Saansain\nJaise Bina Nindiya Ki Raatain Hain Toh\nAur Tu Hi Mere Dil Ki Raza Hai\nTere Bina Dil Bhi Khafa Hai Toh\n";
			Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
        case 4:
        	system("Color 8");
        	PlaySound(TEXT("Tum-hi-ho.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout<< "Lyrics of Tum hi ho:" << endl;
            cout<<"\nHum tere bin ab reh nahi sakte\nTere bina kya wajood mera x (2)\n";
            Sleep(100);
			cout<< "\nTujh se juda gar ho jaayenge\nTo khud se hi ho jaayenge juda\nKyun ki tum hi ho, ab tum hi ho\nKi zindagi ab tum hi ho\nChain bhi, mera dard bhi\nMeri aashiqui ab tum hi ho\n";
			Sleep(100);
			cout<<"\nTera mera rishta hai kaisa\nEk pal door gawara nahi\nTere liye har roz hain jeete\nTujhko diya mera waqt sabhi\nKoi lamha mera na ho tere bina\nHar saans pe naam tera\nKyun ki tum hi ho, ab tum hi ho\nZindagi ab tum hi ho\n";
			Sleep(100);
            cout<<"\nChain bhi, mera dard bhi\nMeri aashiqui ab tum hi ho\nTum hi ho, tumhi ho\n";
            Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
          case 5:
        	system("Color 3");
        	PlaySound(TEXT("Tum-Se-Hi.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout<< "Lyrics of Tum se hi:" << endl;
            cout<<"\nNa hai yeh pana\nNa khona he hai\nTera na hona, jaane\nKuyn hona he hai\n";
            Sleep(100);
			cout<< "\nTum Se Hi din hota hai\nSurmayi shaam aati hai\nTum Se Hi Tum Se Hi\nHar ghadi saans aati hai\nZindagi kehlati hai\nTum Se Hi Tum Se Hi\n";
			Sleep(100);
			cout<<"\nNa hai yeh pana\nNa khona hi hai\nTera na hona, jaane\nKuyn hona hi hai\n";
			Sleep(100);
            cout<<"\nAa aa..aa aa…aa aa..aa aa.. aa..\n";
            Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
        case 6:
        	system("Color E");
        	PlaySound(TEXT("Sukoon.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
            cout<< "Lyrics of Sukoon:" << endl;
            cout<<"\nZindagi\nHai kitni haseen\nHai phir bhi kahin\nAjab tanhayi\nKesi ye veeraniyan\n";
            Sleep(100);
			cout<< "\nChupke se\nYe mujhse kahe\nAgan dil ki\nSulagjane de\nKesi ye veeraniyan\n";
			Sleep(100);
			cout<<"\nTu hi hai sukoon mera\nTu hi hai kayaam ve\nGhar jo savaar de tu\nBarse ga aab ve\n";
			Sleep(100);
            cout<<"\nKabhi tu daraar dil ki\nPaaye gi darya\nJise dhundta sadiyon se\nKare intezar\nZindagi\nHai kitni haseen\nHai phir bhi kahin\nAjab tanhayi\nKesi ye veeraniyan\n";
            Sleep(100);
			getch();
        	PlaySound(0,0,0);
        	getch();
            break;
        default:
            cout << "Invalid Selection" << endl;
    
    }
    system("pause");
}
int main() {
	cout<<"******************************************STARTING UP!!!!**************************************************"<<endl;
	PlaySound(TEXT("car-ignition.wav"),NULL,SND_SYNC);
	cout<<endl;
	cout<<"***********************************************************************************************************"<<endl;
    cout<<"-----------------------------------WELCOME TO MUSIC PLAYER-------------------------------------------------"<<endl;
    cout<<"***********************************************************************************************************"<<endl;
     //already made playlist
    queue<string> playlist;
    string song;
    cout << ".....................................Already made playlist..........................................." << endl;
    song = "                                          GERUA                                                        ";
    playlist.push(song);
    song = "                                       BLINDING LIGHTS                                                  ";
    playlist.push(song);
    song = "                                        BAARISHEIN                                                     ";
    playlist.push(song);
    song = "                                         TUM HI HO                                                        ";
    playlist.push(song);
    song = "                                         TUM SE HI                                                       ";
    playlist.push(song);
    song = "                                          SUKOON                                                          ";
    playlist.push(song);
    // Displaying the playlist
    while (!playlist.empty()) {
        cout << playlist.front() << endl;
        playlist.pop();
    }
    cout<<"........................................................................................................."<<endl;
    
    system("pause");
    int choice;
    cout << "\n-----Song Playlist Application-----\n";
    while(true) {
    system("Color F");
    cout<<"\nSelect the option you would like to choose from the menu:\n";
    cout << "1. Add Music\n";
    cout << "2. Remove Music\n";
    cout << "3. Show Playlist\n";
    cout << "4. Play next file\n";
    cout << "5. Play previous file,\n";
    cout << "6. Play first file\n";
    cout << "7. Play Last file\n";
    cout << "8. search song.\n";
    cout << "9. shuffle song.\n";
    cout << "10. Play playlist\n";
    cout << "11. Exit\n";
    cin >> choice;
    cout<<endl;

    switch(choice) {
        case 1:
            insert();
            break;
        case 2:
            Delete_element();
            break;
        case 3:
            show();
            break;
        case 4:
            next_node();
            break;
        case 5:
            prev_node();
            break;
        case 6:
            first_node();
            break;
        case 7:
            last_node();
            break;
        case 8:
            search();
            break;
        case 9:
            shuffle();
            break;
        case 10:
        	playPlayList();
        	break;
        case 11:
        	return 0;
        	break;
        default:
            cout<<"Invalid Input\n";
   		 }
	}
	return 0;
}

