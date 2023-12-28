#include "pch.h"
#include "SportClub.h"


TEST(SportClubConstructor, SportClubNames) {
	SportClub sportClub;
	EXPECT_TRUE(sportClub.getName() == "PSG");
	EXPECT_TRUE(sportClub.getLocation() == "Paris, FRANCE");

}

TEST(SportClubConstructor, SportClubMembers) {
	SportClub sportClub;
	vector <ClubMember> members = { TeamMember(), TeamMember(Basketball,"2 years", 24, "Herbert", "Female"),
								   Fan(), Fan(Soccer, "3 years", 22,"Virginia", "Female"),
									Coach(), Coach(Volleyball, 46, "Martha", "Female") };
	vector <ClubMember> clubMembers = sportClub.getClubMembers();
	EXPECT_EQ(members.size(), clubMembers.size());
	for (int i = 0; i < clubMembers.size(); i++)
	{
		EXPECT_EQ(members[i].getName(), clubMembers[i].getName());
	}
}

TEST(SportClubConstructor, SportClubTeams) {
	SportClub sportClub;
	vector <Team> teams = { Team(), Team(Basketball, "TsmokiMinsk"), Team(Volleyball, "Olypmiacos") };
	vector <Team> sportClubTeams = sportClub.getTeams();
	EXPECT_EQ(teams.size(), sportClubTeams.size());
	for (int i = 0; i < sportClubTeams.size(); i++)
	{
		EXPECT_EQ(teams[i].getName(), sportClubTeams[i].getName());
	}
}

TEST(SportClubConstructor, SportClubAdmins) {
	SportClub sportClub;
	vector <Admin> admins = { Manager("Brandon", "Bradndomdom") , Bookkeeper("Bob", "boby2005") };
	vector <Admin> clubAdmins = sportClub.getAdmins();
	EXPECT_EQ(admins.size(), clubAdmins.size());
	for (int i = 0; i < clubAdmins.size(); i++)
	{
		EXPECT_EQ(admins[i].getName(), clubAdmins[i].getName());
	}
}

TEST(SportClubFunctions, AddingNewAdmin) {
	SportClub sportClub;
	Bookkeeper newBookkeeper("Dylan", "91131413335");
	sportClub.addNewAdmin(newBookkeeper);
	vector <Admin> clubAdmins = sportClub.getAdmins();
	bool exists = false;
	for (int i = 0; i < clubAdmins.size(); i++)
	{
		if (clubAdmins[i] == newBookkeeper) exists = true;

	}
	EXPECT_TRUE(exists);
}

TEST(SportClubFunctions, AddingNewClubMember) {
	SportClub sportClub;
	Fan newFan(Volleyball, "2 year", 21, "Katerine", "Female");
	sportClub.addNewClubMember(newFan);
	vector <ClubMember> clubMembers = sportClub.getClubMembers();
	bool exists = false;
	for (int i = 0; i < clubMembers.size(); i++)
	{
		if (clubMembers[i] == newFan) exists = true;
	}
	EXPECT_TRUE(exists);
}

TEST(SportClubFunctions, AddingNewTeam) {
	SportClub sportClub;
	Team newTeam(Basketball, "Boston Celtics");
	sportClub.addNewTeam(newTeam);
	vector <Team> sportClubTeams = sportClub.getTeams();
	bool exists = false;
	for (int i = 0; i < sportClubTeams.size(); i++)
	{
		if (sportClubTeams[i] == newTeam) exists = true;
	}
	EXPECT_TRUE(exists);
}

TEST(SportClubFunctions, removingClubMember) {
	SportClub sportClub;
	vector <ClubMember> clubMembers = sportClub.getClubMembers();
	Fan removableFan(Soccer, "3 years", 22, "Virginia", "Female");
	bool exists = false;
	for (int i = 0; i < clubMembers.size(); i++)
	{
		if (clubMembers[i] == removableFan) exists = true;
	}
	EXPECT_TRUE(exists);

	sportClub.removeClubMember(removableFan);
	vector <ClubMember> NEWclubMembers = sportClub.getClubMembers();
	for (int i = 0; i < NEWclubMembers.size(); i++)
	{
		EXPECT_FALSE(NEWclubMembers[i].getName() == "Virginia");
	}
}

TEST(SportClubFunctions, removingTeam) {
	SportClub sportClub;
	vector <Team> teams = sportClub.getTeams();
	Team removableTeam(Basketball, "TsmokiMinsk");
	bool exists = false;
	for (int i = 0; i < teams.size(); i++)
	{
		if (teams[i] == removableTeam) exists = true;
	}
	EXPECT_TRUE(exists);

	sportClub.removeTeam(removableTeam);
	vector <Team> NEWteams = sportClub.getTeams();
	for (int i = 0; i < NEWteams.size(); i++)
	{
		EXPECT_FALSE(NEWteams[i].getName() == "Avangers");
	}
}

TEST(SportClubFunctions, checkingCertificate) {
	SportClub sportClub;
	vector <ClubMember>& members = sportClub.getClubMembers();
	members[3].leftTheClub();
	sportClub.checkForCertificate();
	EXPECT_FALSE(members[3].getName() == "Amanda");
}