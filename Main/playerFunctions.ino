void changeAllPlayerDirections() {
  checkAllButtons();
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      changePlayerDirection(playerIndex);
    }
  }
}

void changePlayerDirection(const byte playerID) {
  // Each player is placed on a different side of the table
  // Hence, their perspective on the snake going "left" or "right" is different
  if(playerID == 0) {     
    // If player 0 pushes "up" button
    if(playerButtonPushed[0][0] == 1) {
      setPlayerDirectionNorth(playerID);
    }
    // If he pushes "right" button
    if(playerButtonPushed[0][1] == 1) {
      setPlayerDirectionEast(playerID);
    }

    // If he pushes the "down" button
    if(playerButtonPushed[0][2] == 1) {
        setPlayerDirectionSouth(playerID);
    }
    // If he pushes the "left" button
    if(playerButtonPushed[0][3] == 1) {
       setPlayerDirectionWest(playerID);
    }
  }

  if(playerID == 1) {
    if(playerButtonPushed[1][0] == 1) {
       setPlayerDirectionWest(playerID);
    }
    if(playerButtonPushed[1][1] == 1) {
      setPlayerDirectionNorth(playerID);
    }
    if(playerButtonPushed[1][2] == 1) {
      setPlayerDirectionEast(playerID);
    }
    if(playerButtonPushed[1][3] == 1) {
      setPlayerDirectionSouth(playerID);
    }
  }

  if(playerID == 2) {
    if(playerButtonPushed[2][0] == 1) {
      setPlayerDirectionSouth(playerID);
    }
    if(playerButtonPushed[2][1] == 1) {
      setPlayerDirectionWest(playerID);    
    }
    if(playerButtonPushed[2][2] == 1) {
      setPlayerDirectionNorth(playerID);
    }
    if(playerButtonPushed[2][3] == 1) {
      setPlayerDirectionEast(playerID);
    }
  }

  if(playerID == 3) {
    if(playerButtonPushed[3][0] == 1) {
      setPlayerDirectionEast(playerID);
    }
    if(playerButtonPushed[3][1] == 1) {
        setPlayerDirectionSouth(playerID);
    }
    if(playerButtonPushed[3][2] == 1) {
       setPlayerDirectionWest(playerID);   
    }
    if(playerButtonPushed[3][3] == 1) {
      setPlayerDirectionNorth(playerID);
    }
  }
}

void setPlayerDirectionNorth(const byte playerID) {
  // We allow it
  players[playerID].goingDirection = directionNorth;
  
}

void setPlayerDirectionSouth(const byte playerID) {
  players[playerID].goingDirection = directionSouth;
}

void setPlayerDirectionEast(const byte playerID) {
  players[playerID].goingDirection = directionEast;
}


void setPlayerDirectionWest(const byte playerID) {
  players[playerID].goingDirection = directionWest;
}

void moveAllPlayers() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      movePlayer(playerIndex);
    }
  }
}

void movePlayer(const byte playerID) {
  // If the player is outside of his player zone
  if(playerZones[players[playerID].headPosition.lineCoordinate][players[playerID].headPosition.columnCoordinate] != players[playerID].zoneColour) {
    // That create a drag based on his position
    createDragOnPlayerPosition(playerID);
  }

  // If the player is in his zone
  if(playerZones[players[playerID].headPosition.lineCoordinate][players[playerID].headPosition.columnCoordinate] == players[playerID].zoneColour) {
    // And if he just reached it back, meaning his drag is longer than 1
    if(players[playerID].drag[0].lineCoordinate != 255 && players[playerID].drag[0].columnCoordinate != 255) {
      // It creates a player zone
      createPlayerZone(playerID);
      // Then the drag is reset
      resetPlayerDrag(playerID);
    }
  }

  if(/* If the player hit his own drag or some drag */ {
    // Player dead
  }  
  // In almost all cases, the player will actually move from 1 pixel
  movePlayerByOnePixel(playerID);
}

void createPlayerZone(const byte playerID) {
  // Should use the drag to create the dedicated zone
  // Carefull about non-recangular drags...

  // Basic idea for "spilling over": from each point, we "spill" over in all directions, as a squares bigger and bigger around it. 
  // If we reach only player zone or drag, it means we're inside
  // If we reach only white spots, that means we're outside
  // And we can even make the decision for all the points coloured along the way.
  // That means we'd need kind of a struct called like "tempZone"; with an attributed "decided" as 0 for undecided, 1 for inside and 2 for outside, that we'd merge with the player zone afterward.
  // What's the most efficient starting point then ?

  // So that would look like:
  // take playerZonematrix
  // plot the drag on it in the player's head colour, as a hack
  // then iterate once on the whole matrix to find the max north of zone & drag, max south, max east, max west
  // Within this rectangle, iterate on each spot
  // If spot is in zone already, we're fine
  // If spot is on the drag, add it to player zone

  // --------------


  // Basic idea with evenness of encountered walls:
  // For each given point within the potential square of the drag
  // Query each direction (north, east, south, west)
  // If I encounter an uneven number of walls of the drag, then that means I am inside
  // If I encounter an even number of walls of the drag, that would mean I am oustside ?
  // To be thought about
  // Additionally, to account for the player origin zone: if we get to it with 0, 1, 3, etc. walls, we're in. If we get to it with 2, 4, 6 walls, we're out.

  // Algo would look like that:
  // take playerZonematrix
  // plot the drag on it in the player's head colour, as a hack
  // then iterate once on the whole matrix to find the max north of zone & drag, max south, max east, max west
  // Within this rectangle, iterate on each spot
  // If spot is in zone already, we're fine
  // If spot is on the drag, add it to player zone
  // If spot is in neither, go on all directions until reaching the rectangle size, and count the number of walls before reaching the rectangle end in each direction
  // If either one of the direction counts a number of walls that is pair and non-zero, then we're outside
  // Else, we're inside

  // That won't work in case the player zone is kind of a G, and he's cutting inside of it. We could have 0,0,0,1 both from outside and inside.
  // The only way to really know if a point is inside or outside is to see if it's linked to an external white spot, or if it's trapped between the player drag and the zone
  // Pathfinding could do that, or we could use the spilling over idea


  // There is only one player zone, as the player can kill himself by walking on his own drag. We get all players a basic 2x2 zone in each corner as a starting basis.
}

// Fully resets the player drag to emptiness, and reset the drag increment to 0
void resetPlayerDrag(const byte playerID) {
  for(byte i = 0; i < maxDragSize; i++) {
    players[playerID].drag[i].lineCoordinate = 255;
    players[playerID].drag[i].columnCoordinate = 255;
    players[playerID].dragIncrement = 0;
  }
}

// Takes the player position, registers it as part of the player drag at the available drag increment space, and increase said increment
void createDragOnPlayerPosition(const byte playerID) {
  players[playerID].drag[players[playerID].dragIncrement].lineCoordinate = players[playerID].headPosition.lineCoordinate;
  players[playerID].drag[players[playerID].dragIncrement].columnCoordinate = players[playerID].headPosition.columnCoordinate;
  players[playerID].dragIncrement++;
}

// Moves player by one pixel, depending on his direction
void movePlayerByOnePixel(const byte playerID) {
  if(players[playerID].goingDirection = directionWest)  {movePlayerByOnePixelWest(playerID);}
  if(players[playerID].goingDirection = directionEast)  {movePlayerByOnePixelEast(playerID);}
  if(players[playerID].goingDirection = directionNorth) {movePlayerByOnePixelNorth(playerID);}
  if(players[playerID].goingDirection = directionSouth) {movePlayerByOnePixelSouth(playerID);}
  
}

void movePlayerByOnePixelNorth(const byte playerID) {
  // If the player reached the top of the matrix
  if(players[playerID].headPosition.lineCoordinate == 0) {
    // We do nothing
  }
  // If he didn't yet
  else {
    players[playerID].headPosition.lineCoordinate = players[playerID].headPosition.lineCoordinate - 1;
    players[playerID].headPosition.columnCoordinate = players[playerID].headPosition.columnCoordinate;
  }
}

void movePlayerByOnePixelSouth(const byte playerID) {
  // If we're already at the bottom of the matrix
  if(players[playerID].headPosition.lineCoordinate == totalDisplayNumberOfRows-1) {
    // We do nothing
  }
  // And if we're not at the bottom
  else {
    // Then we simply increase the line by 1 to go south
    players[playerID].headPosition.lineCoordinate = players[playerID].headPosition.lineCoordinate + 1;
    // And the column doesn't change
    players[playerID].headPosition.columnCoordinate = players[playerID].headPosition.columnCoordinate;
  }
}

void movePlayerByOnePixelEast(const byte playerID) {
    // If we're not already at the right end of the matrix
  if(players[playerID].headPosition.columnCoordinate < totalDisplayNumberOfColumns-1) {
    // we simply avance the head of one column, hence to the right. 
    players[playerID].headPosition.columnCoordinate = players[playerID].headPosition.columnCoordinate + 1;
    // And the line coordinate doesn't change
    players[playerID].headPosition.lineCoordinate = players[playerID].headPosition.lineCoordinate;
  }
}

void movePlayerByOnePixelWest(const byte playerID) {
  // If we're already at the total left of the matirx
  if(players[playerID].headPosition.columnCoordinate == 0) {
    // We do nothing
  }
  // If we're not yet at the total left
  else {
    // Then we simply decrease the column coordinate by 1 to go south
    players[playerID].headPosition.columnCoordinate = players[playerID].headPosition.columnCoordinate - 1;
    // And the line coordinate doesn't change
    players[playerID].headPosition.lineCoordinate = players[playerID].headPosition.lineCoordinate;
  }
}

// Checks if player "playerID" has hit any player's snake body, including life/death logic of the players
void checkIfPlayerDied(const byte playerID) {

}

void checkIfAnyPlayerDied() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      checkIfPlayerDied(playerIndex);
    }
  }
}


void digitalOutputPlayer(const byte playerID) {
  Serial.print("Outputing for player ");
  Serial.print(playerID);
  Serial.print(": \n");
  Serial.print("Is active: ");
  Serial.print(players[playerID].isActive);
  Serial.print("\n");
  Serial.print("Head colour: ");
  Serial.print(players[playerID].headColour);
  Serial.print("\n");
  Serial.print("Colour: ");
  Serial.print(players[playerID].zoneColour);
  Serial.print("\n");
  Serial.print("is alive: ");
  Serial.print(players[playerID].isAlive);
  Serial.print("\n");
}
  
