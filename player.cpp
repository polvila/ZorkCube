#include <iostream>
#include "exit.h"
#include "player.h"
#include "globals.h"
#include "item.h"

Player::Player(const string& name, const string& description, Room* location) :
	Entity(name, description), location(location)
{
	type = PLAYER;
	health = 100;
	hungry = 0;
}

Player::~Player()
{
}

void Player::Look() const
{
	location->Look();
	cout << "\n>";
}

void Player::GoTo(const string& direction)
{	
	bool exitExists = false;
	for (list<Entity*>::const_iterator it = location->container.cbegin(); it != location->container.cend() && !exitExists ; ++it)
	{
		if( (*it)->type == EXIT )
		{
			Exit* exit = static_cast<Exit*>(*it);
			string name = exit->name;
			GetLowerCase(name);
			if (name == direction)
			{
				TryToGoThrowThat(exit);
				exitExists = true;
				break;
			}
		}
	}
	if(!exitExists) cout << "This exit is blocked.\n\n>";
}

void Player::Take(const string& object)
{
	for (list<Entity*>::iterator it = location->container.begin(); it != location->container.end(); ++it)
	{
		string name = (*it)->name;
		GetLowerCase(name);
		if ((*it)->type == ITEM && name == object)
		{
			Add(*it);
			cout << "The item " << (*it)->name << " has been added to your inventory.\n\n>";
			location->container.remove(*it);
			return;
		}
	}
}

void Player::ShowInventory()
{
	if(container.empty())
		cout << "You are empty handed.\n\n>";
	else
	{
		cout << "You are carrying:\n";
		for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
		{
			(*it)->Look();
		}
		cout << "\n>";
	}
}

void Player::Drop(const string& object)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		string name = (*it)->name;
		GetLowerCase(name);
		if (name == object)
		{
			location->Add(*it);
			cout << "The item " << (*it)->name << " has been dropped into the room.\n\n>";
			container.remove(*it);
			return;
		}
	}
}

void Player::PutInside(const string& object, const string& objContainer)
{
	for (list<Entity*>::iterator objectItem = container.begin(); objectItem != container.end(); ++objectItem)
	{
		string objectItemName = (*objectItem)->name;
		GetLowerCase(objectItemName);
		cout << object;
		cout << objectItemName;
		if(objectItemName == object)
		{
			list<Entity*> inventoryAndRoomContainer;
			inventoryAndRoomContainer = container;
			inventoryAndRoomContainer.insert(inventoryAndRoomContainer.end(), location->container.begin(), location->container.end());

			for (list<Entity*>::iterator objectContainer = inventoryAndRoomContainer.begin(); objectContainer != inventoryAndRoomContainer.end(); ++objectContainer)
			{
				string objectContainerName = (*objectContainer)->name;
				GetLowerCase(objectContainerName);
				if(objectContainerName == objContainer && (*objectContainer)->type == ITEM)
				{
					if ((static_cast<Item*>(*objectContainer))->item_type == CONTAINER)
					{
						(*objectContainer)->Add(*objectItem);
						cout << "The item " << (*objectItem)->name << " has been placed inside the " << (*objectContainer)->name << ".\n\n>";
						container.remove(*objectItem);
						return;
					}
				}	
			}
		}
		return;
	}
}

bool Player::HasThisItem(const string& object)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		string name = (*it)->name;
		GetLowerCase(name);
		if ((*it)->type == ITEM && name == object)
			return true;
	}
	return false;
}

void Player::ShowStatus() const
{
	cout << "Health: " << health << "%\n";
	cout << "Hungry: " << hungry << "%\n\n>";
}

void Player::Use(const string& object)
{
	bool objExists = false, isConsumable = false;
	for (list<Entity*>::iterator it = container.begin(); it != container.end();)
	{
		string name = (*it)->name;
		GetLowerCase(name);
		if ((*it)->type == ITEM && name == object)
		{
			objExists = true;
			Item* item = static_cast<Item*>(*it);
			if (item->item_type == HEALTH)
			{
				isConsumable = true;
				IncreaseHealth(item->percentage);
				cout << "After using the item " << item->name << " you have achieved +" << item->percentage << "% of health.\n\n>";
				it = container.erase(it);
			}else if (item->item_type == HUNGRY)
			{
				isConsumable = true;
				DecreaseHungry(item->percentage);
				cout << "After using the item " << item->name << " you have achieved -" << item->percentage << "% of hungry.\n\n>";
				it = container.erase(it);
			}
			else
				++it;
		}
	}
	if (!objExists)
		cout << "You do not have the item " << object << " in your inventory.\n\n>";
	else if (!isConsumable)
		cout << "You can not consume the item " << object << ".\n\n>";
}

void Player::TryToGoThrowThat(Exit* exit) 
{
	string answer;
	if(exit->destination->name != "EXIT!")
	{
		cout << "This tunnel has some written numbers (" << exit->destination->name << ") and leads to a ";
		string color = exit->destination->color;
		GetUpperCase(color);
		PrintColorNameWithColor(color);
		cout << " room."
			<< " Are you sure to go through this tunnel? (yes/no)\n\n>";

		getline(cin, answer);

		if(answer == "yes")
			ChangePlayerLocationAndLook(exit->destination);
		else
			cout << "You are still in the same room.\n\n>";
	}else
		ChangePlayerLocationAndLook(exit->destination);
}

void Player::ChangePlayerLocationAndLook(Room* destination)
{
	this->location = destination;
	this->Look();
}

bool Player::DecreaseHealth(int percentage)
{
	if (health > percentage)
	{
		health -= percentage;
		return false;
	}
	health = 0;
	return true;
}

void Player::IncreaseHealth(int percentage)
{
	if (100 < health + percentage)
		health = 100;
	else
		health += percentage;
}

void Player::DecreaseHungry(int percentage)
{
	if (0 > hungry - percentage)
		hungry = 0;
	else
		hungry -= percentage;
}

bool Player::IncreaseHungry(int percentage)
{
	if (hungry + percentage < 100)
	{
		hungry += percentage;
		return false;
	}
	hungry = 100;
	return true;
}

void Player::Open(const string& object)
{
	list<Entity*> inventoryAndRoomContainer;
	inventoryAndRoomContainer = container;
	inventoryAndRoomContainer.insert(inventoryAndRoomContainer.end(), location->container.begin(), location->container.end());
	for (list<Entity*>::iterator it = inventoryAndRoomContainer.begin(); it != inventoryAndRoomContainer.end(); ++it)
	{
		if((*it)->type == ITEM)
		{
			string name = (*it)->name;
			GetLowerCase(name);
			if (static_cast<Item*>(*it)->item_type == CONTAINER && (*it)->name == object)
			{
				if(!(*it)->container.empty())
				{
					this->container.insert(this->container.end(), (*it)->container.begin(), (*it)->container.end());
					(*it)->container.clear();
					cout << "The items in the " << (*it)->name << " have been added to your inventory.\n\n>";
				}
				else
					cout << "The item " << (*it)->name << " is empty.\n\n>";
			}
		}
	}
}
