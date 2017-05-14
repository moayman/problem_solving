#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;



int main()
{
	map<unsigned int, set<string>, greater<unsigned int>> processedData;
	unordered_map<string, unsigned int> numberOfParticipants;
	unordered_map<string, set<string>> participantProjects;
	string input, project;
	while (getline(cin, input))
	{
		if (input[0] == '1')
		{
			// Remove people who signed up for more than 1 project
			for (unordered_map<string, set<string>>::iterator it = participantProjects.begin(); it != participantProjects.end(); it++)
			{
				if (it->second.size() > 1)
				{
					for (set<string>::iterator projectToRemove = it->second.begin(); projectToRemove != it->second.end(); projectToRemove++)
					{
						numberOfParticipants[*projectToRemove]--;
					}
				}
			}
			// map projects using number of participants
			for (unordered_map<string, unsigned int>::iterator it = numberOfParticipants.begin(); it != numberOfParticipants.end(); it++)
			{
				processedData[it->second].insert(it->first);
			}
			// print data
			for (map<unsigned int, set<string>>::iterator it = processedData.begin(); it != processedData.end(); it++)
			{
				for (set<string>::iterator toOutput = it->second.begin(); toOutput != it->second.end(); toOutput++)
				{
					cout << *toOutput << ' ' << it->first << endl;
				}
			}
			processedData.clear();
			numberOfParticipants.clear();
			participantProjects.clear();
			continue;
		}
		if (input[0] == '0')
			break;
		if (isupper(input[0]))
		{
			numberOfParticipants[input];
			project = input;
		}
		else
		{
			// prevent increasing number of participants of a project for people who signed up more than once for the same project
			if (participantProjects[input].find(project) == participantProjects[input].end())
			{
				numberOfParticipants[project]++;
				participantProjects[input].insert(project);
			}
		}
	}
	return 0;
}