#include "pch.h"

#include <queue>

//+1. Sprawdzic czy nowo utworzona kolejka jest pusta
//+2. Sprawdzic czy jak dodamy kilka elementów (push) to size sie zmieni na prawidlowa wartosc
//3. Sprawdzic czy jak wywo³amy pop na kolejce z elemntami to zmniejszy sie jej rozmiar
//4. Sprawdzic czy jak za pomoca push w³o¿y³y elementy o zadanych wartosciach to po wywo³aniu pop odpowiednio bêdzie ustawiony front
//5. Sprawdzic czy jak wrzucimy 5 elementów i potem 5 razy wywo³amy pop to kolejka bedzie pusta. (polecam uzyc petli for)
//5*. Swap

TEST(QueueTest, TestNewQueueIsEmpty) 
{
	std::queue<int> testedQueue;

	EXPECT_TRUE(testedQueue.empty());
}

TEST(QueueTest, TestAdding3Elemnts)
{
	std::queue<int> testedQueue;
	for (int i = 0; i < 3; ++i)
	{
		testedQueue.push(i);
	}

	EXPECT_EQ(testedQueue.size(), 3);
}

TEST(QueueTest, TestRemovingElements)
{
	const size_t desiredQueueSize = 10;
	std::queue<int> testedQueue;
	for (int i = 0; i < desiredQueueSize; ++i)
	{
		testedQueue.push(i);
	}

	EXPECT_EQ(testedQueue.size(), desiredQueueSize);
	testedQueue.pop();
	EXPECT_EQ(testedQueue.size(), desiredQueueSize-1);
}

TEST(QueueTest, TestElementOrderUsingPop)
{
	const size_t desiredQueueSize = 10;
	std::queue<int> testedQueue;
	for (int i = 0; i < desiredQueueSize; ++i)
	{
		testedQueue.push(i);
	}

	for (int i = 0; i < desiredQueueSize; ++i)
	{
		EXPECT_EQ(testedQueue.front(), i);
		testedQueue.pop();
	}
}

TEST(QueueTest, TestEmptyingQueue)
{
	const size_t desiredQueueSize = 5;
	std::queue<int> testedQueue;
	for (int i = 0; i < desiredQueueSize; ++i)
	{
		testedQueue.push(i);
	}

	for (int i = 0; i < desiredQueueSize; ++i)
	{
		testedQueue.pop();
	}

	EXPECT_TRUE(testedQueue.empty());
}