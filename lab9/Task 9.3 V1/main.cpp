#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

enum genre { pop, Jazz, Classic, HipHop};

struct album {
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string trackLocation;
};

void albumAdd() {

    vector<album> albums;

    int vectorSize = albums.size();

    albums.resize(vectorSize + 5);

    cout << " " << endl;
    cout << "Enter Album Title:" << endl;
    cin >> albums[vectorSize + 1].album_name;

    cout << "Enter Genre: 0 --> Pop, 1 --> Jazz, 2 --> Classic, 3 --> Hip-Hop" << endl;
    cin >> albums[vectorSize + 2].kind;

    cout << "Enter number of tracks within album:" << endl;
    cin >> albums[vectorSize + 3].track_number;

    cout << "Enter the title for these " << albums[vectorSize + 4].track_number << " tracks:" << endl;

    for (int i = 0; i < albumNumber.track_number; i++) {
        cin >> albumNumber.tracks[i];
    }

    cout << "Enter the file location for the album tracks:" << endl;
    cin >> albums[vectorSize + 6].trackLocation;
}

void printAlbum() {
    cout << "PrintAlbum" << endl;
}

void playTrack() {
    cout << "playTrack" << endl;
}



int main()
{
    int menuOption;

    // Menu Options
    cout << "Enter the option: " << endl;
    cout << "1. Add an Album" << endl;
    cout << "2. Print the album tracks" << endl;
    cout << "3. Play a track from an album" << endl;
    cout << "4. Exit" << endl;

    cin >> menuOption;

    switch(menuOption) {
    case 1:
            albumAdd();
            break;
    case 2:
            printAlbum();
            break;
    case 3:
            playTrack();
            break;
    case 4:
            exit(0);

    }
    return 0;
}

