#pragma once

#include <cstring>

struct User {
	unsigned id;
	char name[128];

private:
	User() = default; // Prevents the default constructor from being used
	User(const User &other) = default; // Prevents the copy constructor from being used
	User(User &&other) = default; // Prevents the move constructor from being used
	User &operator=(const User &other) = default; // Prevents the copy assignment operator from being used
	User &operator=(User &&other) = default; // Prevents the move assignment operator from being used

public:
	struct User create_user(const char *curr_name) {
		static unsigned last_id = 0; // Keeps track of the last assigned ID

		struct User new_user{};
		new_user.id = last_id++; // Assign the next unique ID
		strncpy(new_user.name, curr_name, sizeof(new_user.name) - 1); // Copy the curr_name, ensuring it doesn't overflow the buffer
		new_user.name[sizeof(new_user.name) - 1] = '\0'; // Ensure the curr_name is null-terminated

		return new_user;
	}
};
