#include <iostream>
#include <vector>

using namespace std;

enum genre{pop, Jazz, Classic, HipHop};

struct album {
    string album_name;
    genre kind;
    int track_number;
    string tracks[5];
    string tracklocation;
};

int menu() {
    int menuSelection;

    cout << "1. Add an album" << endl;
    cout << "2. Print the album details" << endl;
    cout << "3. Play a track from an album" << endl;
    cout << "4. Exit Program" << endl;
    cin >> menuSelection;

    return menuSelection;
}

struct album addAlbum(vector<album> albums) {
    int temp;

    cout << "Enter album name: " << endl;
    cin >> albums.push_back(album.album_name);

    cout << "Enter genre 0->Pop, 1->Jazz, 2->Classic, 3->HipHop" << endl;
    cin >> temp;
    album.kind = static_cast<genre>(temp);

    cout << "Enter number of tracks within albums" << endl;
    cin >> album.track_number;

    cout << "Enter the title for these " << album.track_number << " tracks" << endl;

    for (int i = 0; i < album.track_number; i++) {
        cin >> album.tracks[i];
    }

    cout << "Enter the file location for tracks" << endl;
    cin >> album.tracklocation;

    //albums.push_back(album.album_name, album.kind, album.track_number, album.tracks, album.tracklocation);

    return albums;
}

int main()
{
    //Variable Initilization
    bool z = true;
    int menuSelection;
    vector<album> albums;

    //Menu loop
    while(z) {
        menuSelection = menu();
            switch(menuSelection) {
                case 1:
                    addAlbum(albums);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    cout << "Exiting Program..." << endl;
                    z = false;
                    break;
        }
    }


    return 0;
}
