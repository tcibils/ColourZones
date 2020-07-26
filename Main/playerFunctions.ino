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
    
  }
  // Player moves from 1 pixel
  // That create a drag

  // If the player reached his zone or his drag
  // Then the drag is reset
  // And it creates some player zone
  // The player still moves from 1 pixel
  
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
  
