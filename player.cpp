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

	FillPossibleDirections();
}

Player::~Player()
{
}

bool Player::Look()
{
	location->Look();
	cout << "\n>";
	return true;
}

bool Player::GoTo(const string& direction)
{	
	if(IsAPossible(direction))
	{
		Entity* exit = Find(location->container, EXIT, direction);
		if(exit != nullptr)
			TryToGoThrowThat(static_cast<Exit*>(exit));
		else
			cout << "This exit is blocked.\n\n>";
		return true;
	}
	return false;
}

bool Player::Take(const string& object)
{
	Entity* item = Find(location->container, ITEM, object);
	if (item != nullptr)
	{
		Add(item);
		cout << "The item " << item->name << " has been added to your inventory.\n\n>";
		location->container.remove(item);
		return true;
	}
	return false;
}

bool Player::ShowInventory() const
{
	if(container.empty())
		cout << "You are empty handed.\n\n>";
	else
	{
		cout << "You are carrying:\n";
		for (list<Entity*>::const_iterator it = container.cbegin(); it != container.cend(); ++it)
			(*it)->Look();
		cout << "\n>";
	}
	return true;
}

bool Player::Drop(const string& object)
{
	Entity* item = Find(container, ITEM, object);
	if (item != nullptr)
	{
		location->Add(item);
		cout << "The item " << item->name << " has been dropped into the room.\n\n>";
		container.remove(item);
		return true;
	}
	return false;
}

bool Player::PutInside(const string& object, const string& objContainer)
{
	if (HasThisItem(object))
	{
		Entity* item = Find(container, ITEM, object);
		Entity* itemContainer = Find(JoinLists(container, location->container), ITEM, objContainer);
		if(itemContainer != nullptr && static_cast<Item*>(itemContainer)->item_type == CONTAINER)
			PutItemInsideItemContainer(item, itemContainer);
		else cout << "You can not put the item " << item->name << " inside the " << itemContainer->name << " item.\n\n>";
	}
	else cout << "You have not the item " << object << " in your inventory.\n\n>";
	return true;
}

bool Player::HasThisItem(const string& object) const
{
	if (Find(container, ITEM, object) != nullptr)
		return true;
	return false;
}

bool Player::ShowStatus() const
{
	cout << "Health: " << health << "%\n";
	cout << "Hungry: " << hungry << "%\n\n>";
	return true;
}

bool Player::Use(const string& object)
{
	Entity* entity = Find(container, ITEM, object);
	if (entity != nullptr)
	{
		if (static_cast<Item*>(entity)->item_type == HEALTH)
			UseHealthIncrementer(entity);
		else if (static_cast<Item*>(entity)->item_type == HUNGRY)
			UseHungryDecrementer(entity);
		else cout << "You can not consume the item " << object << ".\n\n>";
	}else cout << "You do not have the item " << object << " in your inventory.\n\n>";
	return true;
}

void Player::TryToGoThrowThat(Exit* exit) 
{ 
	if(exit->destination->name != "EXIT!")
		TunnelConfirmation(exit->destination);
	else
		ChangePlayerLocationAndLook(exit->destination);
}

void Player::ChangePlayerLocationAndLook(Room* destination)
{
	this->location = destination;
	this->Look();
}

Entity* Player::Find(list<Entity*> container, const EntityType& entityType, const string& entityName)
{
	for (list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		string name = (*it)->name;
		GetLowerCase(name);
		if ((*it)->type == entityType && name == entityName)
			return *it;
	}
	return nullptr;
}

bool Player::IsAPossible(string direction) const
{
	for (vector<string>::const_iterator it = directions.cbegin(); it != directions.cend(); ++it)
		if ((*it) == direction)
			return true;
	return false;
}

void Player::UseHealthIncrementer(Entity* entity)
{
	Item* item = static_cast<Item*>(entity);
	IncreaseHealth(item->percentage);
	cout << "After using the item " << item->name << " you have achieved +" << item->percentage << "% of health.\n\n>";
	container.remove(entity);
}

void Player::UseHungryDecrementer(Entity* entity)
{
	Item* item = static_cast<Item*>(entity);
	DecreaseHungry(item->percentage);
	cout << "After using the item " << item->name << " you have achieved -" << item->percentage << "% of hungry.\n\n>";
	container.remove(entity);
}

void Player::MoveItemsToInventory(Entity* itemContainer)
{
	this->container.insert(this->container.end(), itemContainer->container.begin(), itemContainer->container.end());
	itemContainer->container.clear();
	cout << "The items in the " << itemContainer->name << " have been added to your inventory.\n\n>";
}

void Player::PutItemInsideItemContainer(Entity* item, Entity* itemContainer)
{
	itemContainer->Add(item);
	cout << "The item " << item->name << " has been placed inside the " << itemContainer->name << ".\n\n>";
	container.remove(item);
}

void Player::FillPossibleDirections()
{
	directions.push_back("north");
	directions.push_back("south");
	directions.push_back("east");
	directions.push_back("west");
	directions.push_back("up");
	directions.push_back("down");
}

void Player::TunnelConfirmation(Room* destination)
{
	string answer;
	cout << "This tunnel has some written numbers (" << destination->name << ") and leads to a ";
	destination->PrintColorRoom();
	cout << " room. Are you sure to go through this tunnel? (yes/no)\n\n>";

	getline(cin, answer);

	if (answer == "yes") ChangePlayerLocationAndLook(destination);
	else cout << "You are still in the same room.\n\n>";
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

bool Player::Open(const string& object)
{
	Entity* entity = Find(JoinLists(container, location->container), ITEM, object);
	if(entity != nullptr)
	{
		if (static_cast<Item*>(entity)->item_type == CONTAINER && !entity->container.empty())
			MoveItemsToInventory(entity);
		else
			cout << "The item " << entity->name << " is empty.\n\n>";
		return true;
	}
	return false;
}
