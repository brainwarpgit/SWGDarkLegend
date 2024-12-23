# SWGDarkLegend is a project I have been working on for quite a while now.   I wanted to build a version of SWG that was easy for people to work with.   It was originally intended to be a solo play server, but after working on it, its really setup to be any type of server.  

# This code is not being hosted at this time and currently there are no plans to host one.

Before we get started I would like to give a shout out to the projects that inspired alot of the changes.   I tried not to just blatantly copy any code, but sometimes, it was already the best way to accomplish the goal.  Most everything was pulled from suggestions just to see if I could make it work.  No assets from any project were taken.  Only assets from MTG tres are used.

SWGEMU Core3 Team, Mod the Galaxy, Empire in Flames, Infinity, Attack of the Clones, Cyvster's Solo, YOURSWG(mySWG), Flurry, Tarkins Revenge, Legend of Hondo, SmashSWG, SWG Animus, and I'm sure there is more, but thats what I have in my list.

SWGDarkLegend is based on the current Core3 platform released by SWGEMU.   The tre files are based on ModTheGalaxy and custom tre built specifically for SWGDarkLegend.

This build is based off of the update-wip branch on <a href="https://github.com/modthegalaxy/mtgserver">MTGServer</a>. (Thanks Hakry and the MTG Team)  You can download the tre files from this link.

I have kept it up to date with SWGEMU Core3.

I use the SWGEmu launcher to launch the game.

My ultimate goal for this release was to just have fun!   I enjoy codings and looking through swg channel discords for recommendations and/or ideas and seeing if I can make it happen.   Some of these ideas I had on my own, which for me is honestly surprising.

There is a tre file that I have built for certain things in the game.   You can download it here <a href="https://drive.google.com/file/d/1IZmZ3Vzqi8dOEc1qloD24M7UxS6bIzhv/view?usp=sharing">SWGDL_update_01.tre</a>

I also have the swgemu_live.cfg available.  <a href="https://drive.google.com/file/d/12Lsg6REZ4f8kR6R8c--PXw1KvH0II0xL/view?usp=sharing">swgemu_live.cfg</a>

My list of "patch notes" <a href="https://docs.google.com/document/d/15YycRalQSvf7pH6e_128wsscAuUSe9zM253E80z9BQc/edit?usp=sharing">Patch Notes</a>

Some things I have been able to accomplish that are different than other servers.  (Some of these may be child play, others took some time)

1.  There is a VaribleWatcher setup where things can be changed quickly and "only the fly". These are setup in different variable types professions/player/creature/etc. No need for server restarts to change xp rates for example.   I tried to tie most if not all changes to these variables in some form.
    There are too many variables to list here.   You can find them in /bin/scripts/managers/variables/

2.  Beginning items are now achieved during the Helper Droid quest line versus being given to you.   OR you can get a base set of items from the DL Services Terminal outside any starport.

3.  Padawan Trials now grant jedi_general xp on completion.

4.  The new Legendary/Exceptional modifiers system in Core3 now affects weapons and armor as well as components including Saber Crystals and Pearls.

5.  Junk Dealer takes all items, but actually has a minimum credit if no value is assigned during item creation.

6.  Added Elite / Heroic spawns to all facets of the game.   These creatures have higher stats than normal creatures and reward accordingly.

7.  Adjustable Cave, POI, and Dungeon difficulty through the new Variables system cdpVariables.  (server restart on changes)

8.  Added craftingCraftedItemsBetterThanLootEnabled variable to attempt to keep looted items subpar or better to crafted items. (preference)

9.  Most NGE(/shudder) houses and vehicles are craftable in game and assigned to the appropriate profession.  I still work on adding anything I missed as I can.

10.  Adding Shuttles to locations in the game that currently don't exist can be done without tre edits.

11.  Junk loot no longer gets modifier tags such as Legendary/Exceptional

12.  Completely changed the jedi unlock path.   You can unlock at anytime at a Force Shrine.   You are not required to complete the village quests, but you are required to complete all 16 trees of FS before you can continue to Mellichae.   XP conversion rates are dependant on badges.   The more badges you have, the better the XP conversion.

13.  Jedi Knight Trials now requires mastery of 3 Jedi Disciplines.   Not required to go overt for trials.

14.  Weapon Type damage multlipliers in combatVariables

15.  All XP type multipliers in playerXpVariables

16.  Add missionRandomAttack to Mission Terminals.   You can set the level and speed at which you will be attacked.   This is available to all players.

17.  You can now craft while Entertaining.   craftingVariables

18.  Player / Pet / Vehicle speed modifiers in mountVariables and playerVariables.  (mySWG Inspiration)  BUT petSpeedSameAsPlayer in mountVariables will allow you pets to keep up with you at all times.   Including Force Run / Burst Run / Gallop / Vehicles etc..

19.  Gallop and Burst Run are toggable.  (HAM damage)

20.  Attachment Splitting.   Allows you to split attachments that have more than 1 mod.

21.  Wearables/Armor/Weapon Attachment Splitting.   Allows you to split the attachments from these items at the expense of losing the item.

22.  Critical Damage / Sampling / Healing / Harvesting now in game along with new CA/AA.

23.  Force Crystals Renamed and Color added to name of color crystals.

# SWGEmu Core3: Recreating the Classic Star Wars Galaxies Experience

## What is SWGEmu?

Star Wars Galaxies (SWG) was an immensely popular massively multiplayer online role-playing game (MMORPG) introduced by Sony Online Entertainment in 2003. Despite its eventual shutdown in 2011, SWG left a lasting legacy in the hearts of thousands of players.

The SWGEmu project aims to recapture the magic of the game by focusing on a specific milestone: Pre-CU, or Pre-Combat Upgrade. The Combat Upgrade introduced significant changes to the gameplay, which were met with disapproval by many devoted players. It was in response to these changes that the SWGEmu project was born—a collective effort to "recreate" the game as it existed during the Pre-CU era.

At the core of the SWGEmu project lies the "Emulator," referring to the meticulously crafted server software being developed by the SWGEmu team. This Emulator endeavors to faithfully mimic Sony Online Entertainment's server-side software, which once hosted the immersive galaxies of Star Wars Galaxies during the Pre-CU era. To achieve this ambitious goal, the SWGEmu team has dedicated countless hours to reverse-engineering the code from scratch. They have built their own custom engine and core game logic, ensuring that every detail is crafted with love and precision.

The SWGEmu project is not only a nostalgic journey for passionate players but also a testament to the dedication and perseverance of a talented team. By resurrecting the Pre-CU era, SWGEmu offers an opportunity for both veterans and newcomers to experience the rich and captivating universe of Star Wars Galaxies, as it was once cherished by thousands of fans.

If you have any questions, need support, or want to contribute to the SWGEmu project, please refer to the documentation and resources provided in this repository.

## Docker Build

If you have docker (i.e. Linux docker daemon, Windows/MacOS [Docker Desktop](https://www.docker.com/products/docker-desktop/)) you can run the entire development environment and server in a container.

### Setup

The docker build creates a container that includes everything needed to run the core3 engine except you need the tre files from the client.

The setup assumes you've copied your tre files to the docker volume 'shared-tre' and in the container they're mounted in /tre/

On linux or macos you can easily create this volume by doing:

```
$ cd ~/SWGEmu
$ tar cf - *.tre | docker run -i --rm -v shared-tre:/tre debian:bullseye bash -c 'tar xvf - -C /tre'
bottom.tre
...
patch_sku1_14_00.tre
```

The docker container will use these files for your server in the container.

### Build

To build the container:

```
cd docker
./build.sh
```

### Develop/Run

Run the container with:

```
cd docker
./run.sh
```

This runs the container and starts and interactive shell, in there you can work with the code (workspace/Core3), build and run the server.

The first time you run the container it will setup the environment and defaults for the server, watch for it to tell you the mysql and admin passwords!

When you're in the container you should have a ~/.my.cnf setup which allows you to easily talk to the mysql sever with the mysql command line client.

All the local configuration is in workspace/Core3/MMOCoreORB/bin/conf/config-local.lua

#### Compile the server

Inside the container type:

```
build
```

#### Run the server

Inside the container type:

```
run
```

## Windows Subsystem for Linux Setup

There is an automated setup available for Windows 10+ with WSL.

See [wsl2/README.md](wsl2/README.md) for instructions.

## Linux Automated Setup

You can use the automated linux setup if you plan to run the server in a vm or dedicated cloud or metal server.

See [linux/README.md](linux/README.md) for instructions.

## Linux Manual Build

### Dependencies
  * Debian 12
  * CMake 3.18.0+
  * BerkeleyDB 5.3
  * MariaDb Client and Server
  * OpenSSL libraries
  * pthreads
  * Lua 5.3 libraries
  * Zlib libraries
  * clang18
  * java runtime
  * boost
  * ninja-build

#### Clang-18

The easiest way to get the clang18 to build with is to use the script provided by the llvm repo:

```
sudo -i
apt-get install -y apt-transport-https ca-certificates git gnupg lsb-release moreutils software-properties-common wget
wget -O /tmp/llvm.sh https://apt.llvm.org/llvm.sh
chmod +x /tmp/llvm.sh
/tmp/llvm.sh 18 all
(set +x;cd /usr/bin;for i in ../lib/llvm-*/bin/*; do ln -sfv $i .; done)
clang --version
ld.lld --version
exit
```

This will install the latest and symlink all the files to /usr/bin so CMake finds them etc.

### Build

  * Install dependencies (Debian 12)

        sudo apt install build-essential libmariadb-dev libmariadb-dev-compat liblua5.3-dev libdb5.3-dev libssl-dev cmake git default-jre libboost-all-dev gdb ninja-build

  * Clone core3 repository somewhere  (~/workspace)

        mkdir -p ~/workspace
        cd ~/workspace
        git clone https://review.swgemu.com/Core3

  * Build Core3

        cd Core3/MMOCoreORB
        make -j$(nproc)

  * Import sql database into mariadb

        sudo apt-get install mariadb-server
        Setup MariaDB User, database and import sql/swgemu.sql

### How to Run

    cd ~/workspace/Core3/MMOCoreORB/bin
    ./core3

# License

    Copyright (C) 2019 SWGEmu

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License along with this program.
    If not, see <http://www.gnu.org/licenses/>.

For more information, see [https://review.swgemu.com/](https://www.docker.com/products/docker-desktop/) or our official [Development Discussion](https://www.swgemu.com/forums/forumdisplay.php?f=10) forums.

# Donate

The SWGEmu project is a 100% volunteer effort and funded by community donations. Consider [donating](https://www.swgemu.com/donate/?rm) to help keep the project moving forward. We use the donations to pay for our infrastructure and services to support the development process and running test servers.
