#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>

class CustomMessages
{
private:
    std::vector<std::string> message_array = { "Embrace the unknown and make today the day you turn possibilities into realities. Your journey begins now.",
        "Challenge yourself to be a beacon of positivity today. Small acts of kindness can create waves of change." }; // This is just used if no messages have been added

    bool use_custom_messages = false;
    bool use_all_messages = true;

public:
    void add_new_message(std::string message)
    {
        message_array.push_back(message);
    }

    void remove_default_messages()
    {
        message_array.erase(message_array.begin(), message_array.begin() + 2);
    }

    std::string get_random_message()
    {
        if (message_array.empty())
        {
            return "No messages available.";
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, message_array.size() - 1);

        int random_index = dist(gen);

        return message_array[random_index];
    }
};
