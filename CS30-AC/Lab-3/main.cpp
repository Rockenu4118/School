#include <memory>
#include <iostream>
#include <string>
#include <optional>

using namespace std;

struct FootballPlayer {
	string name;
	int num;
};

struct Node
{
    FootballPlayer player;
    shared_ptr<Node> next;
};


class FootballRoster {
    public:
	    // Adds a FootballPlayer to the roster.
	    void addPlayer(FootballPlayer player)
        {
            insertToFront(player);
        }
    
	    // deletes the first FootballPlayer that matches name
	    bool deletePlayer(string name)
        {
            shared_ptr<Node> prev = nullptr;
            shared_ptr<Node> curr = head;

            if (curr == nullptr)
                return false;

            while (curr != nullptr)
            {   
                if (curr->player.name == name)
                {
                    prev->next = curr->next;
                    curr.reset();
                    return true;
                }

                prev = curr;
                curr = curr->next;
            }

            return false; 
        }
    
	    // Uses a weak_ptr to return true if there exists a favorite player, false otherwise 
	    bool setFavorite(string name)
        {
            shared_ptr<Node> temp = head;

            while (temp != nullptr)
            {
                if (temp->player.name == name)
                {
                    favorite = temp;
                    return true;
                }

                temp = temp->next;
            }

            return false; 
        }
    
	    // Returns an optional parameter if there is a favorite player
	    std::optional<FootballPlayer> getFavorite() const
        { 
            std::optional<FootballPlayer> favPlayer;

            std::shared_ptr<Node> fav = favorite.lock();

            if (fav != nullptr)
                favPlayer = fav->player;

            return favPlayer;
        }

	    // Prints the list of FootBallPlayers on the roster
	    void printPlayers() const
        {
            shared_ptr<Node> temp = head;

            while (temp != nullptr)
            {
                cout << temp->player.name << " #" << temp->player.num << endl;
                temp = temp->next;
            }
        }

    private:
        void insertToFront(FootballPlayer player)
        {
            shared_ptr<Node> newNode = make_shared<Node>();
            newNode->player = player;
            newNode->next = head;
            head = newNode;
        }

        std::shared_ptr<Node> head = nullptr;

        std::weak_ptr<Node> favorite;
};

 // prints out the name of the favorite player or a message 
 // stating there is no favorite player.
void favoritePlayer(const FootballRoster& roster)
{
    if (roster.getFavorite().has_value())
        std::cout << "You favorite player is: " << roster.getFavorite()->name << endl;
    else 
        std::cout << "You don't have a favorite player" << endl;
}



int main() 
{
	FootballPlayer fb1{ "Matthew Stafford", 9 };
	FootballPlayer fb2{ "Aaron Donald", 99 };
	FootballPlayer fb3{ "Jalen Ramsey", 5 };

	FootballRoster roster;

	roster.addPlayer(fb1);
	roster.addPlayer(fb2);
	roster.addPlayer(fb3);

	roster.printPlayers();
	roster.setFavorite("Aaron Donald");

	favoritePlayer(roster);

	roster.deletePlayer("Aaron Donald");
	favoritePlayer(roster);
}
