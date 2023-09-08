#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to replace placeholders in a string with a specific value
// when working with large strings or objects, making copies can be inefficient in terms of memory and time (calling by value).
// By using references, you avoid making unnecessary copies, which can be a significant performance improvement.
string replacePlaceholder(string text, const string& placeholder, const string& value) {
    // Finding the position of the placeholder
    size_t pos = text.find(placeholder);
    // Replacing the placeholder with the value
    text.replace(pos, placeholder.length(), value);
    return text;
}

int main() {
    // Open the template file for reading
    ifstream templateFile("Invitation_Template.txt");

    // Check file 
    if (!templateFile) {
        // to print some information or error on the console
        cerr << "Error opening template file." << endl;
        return 1; // Exit with an error code
    }

    // Read the template content
    string templateContent;
    string line;
    // Reading data from 'templateFile' and storing it in 'line'
    while (getline(templateFile, line)) {
        // Appending the 'templateContent'
        templateContent += line + '\n';
    }
    // Closing the file
    templateFile.close();

    // List of guest names
    string guestNames[] = { "Alice", "Bob", "Charlie", "David", "Joseph" };
    // vector<string> guestNames = { "Alice", "Bob", "Charlie", "David" };


    // Generate invitation letters for each guest
    // Iterating through the List
    for (const string& guestName : guestNames) {
        string invitationLetter = replacePlaceholder(templateContent, "[NAME]", guestName);

        // Create a file for each guest
        ofstream guestFile(guestName + "_invitation.txt");

        // Check file
        if (!guestFile) {
            cerr << "Error creating invitation file for " << guestName << endl;
            continue; // Skip this guest and continue with others
        }

        // Write the customized invitation letter to the guest's file
        guestFile << invitationLetter;
        guestFile.close();

        cout << "Invitation letter for " << guestName << " created successfully." << endl;
    }

    return 0;
}
