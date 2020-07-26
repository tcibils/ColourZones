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
  Serial.print(players[playerID].colour);
  Serial.print("\n");
  Serial.print("is alive: ");
  Serial.print(players[playerID].isAlive);
  Serial.print("\n");
}
  
