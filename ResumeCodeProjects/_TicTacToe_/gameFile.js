const Gameboard = (() => {
    let board = ["", "", "", "", "", "", "", "", ""];
  
    const updateBoard = (index, marker) => {
      board[index] = marker;
    };
  
    const resetBoard = () => {
      board = ["", "", "", "", "", "", "", "", ""];
    };
  
    const getBoard = () => {
      return board;
    };
  
    return { updateBoard, resetBoard, getBoard };
  })();
  

  const Player = (name, marker) => {
    const getName = () => name;
    const getMarker = () => marker;
  
    return { getName, getMarker };
  };
  
  // DOM elements
  const cells = document.querySelectorAll(".cell");
  const status = document.querySelector("#status");
  const player1Input = document.querySelector("#player1");
  const player2Input = document.querySelector("#player2");
  const startButton = document.querySelector("#start");
  
  let player1, player2, currentPlayer;
  
  
  const startGame = () => {
    player1 = Player(player1Input.value, "X");
    player2 = Player(player2Input.value, "O");
    
    const randomNum = Math.random();

    if (randomNum < 0.5) {
        currentPlayer = player1;
      } else {
        currentPlayer = player2;
      }
    

    Gameboard.resetBoard();
    renderBoard();
    status.textContent = `${currentPlayer.getName()}'s turn`;
    cells.forEach(cell => cell.addEventListener("click", handleCellClick));
    startButton.disabled = true;
  };
  
  
  const renderBoard = () => {
    const board = Gameboard.getBoard();
    cells.forEach((cell, index) => {
      cell.textContent = board[index];
    });
  };
  
  
  const handleCellClick = e => {
    const index = e.target.dataset.cell;
    if (Gameboard.getBoard()[index] !== "") return;
    Gameboard.updateBoard(index, currentPlayer.getMarker());
    renderBoard();
    if (checkForWin()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClick));
      status.textContent = `${currentPlayer.getName()} wins!`;
      startButton.disabled = false;
      return;
    }
    if (checkForTie()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClick));
      status.textContent = "It's a tie!";
      startButton.disabled = false;
      return;
    }
    currentPlayer = currentPlayer === player1 ? player2 : player1;
    status.textContent = `${currentPlayer.getName()}'s turn`;
  };
  
  
  const checkForWin = () => {
    const board = Gameboard.getBoard();
    
    // this *should* be all the winning combinations. I just copied from wikipedia (https://en.wikipedia.org/wiki/Tic-tac-toe#Strategy)  so hopefully none are missing 
    const winningCombos = [
      [0, 1, 2],
      [3, 4, 5],
      [6, 7, 8],
      [0, 3, 6],
      [1, 4, 7],
      [2, 5, 8],
      [0, 4, 8],
      [2, 4, 6]
    ];
    for (let combo of winningCombos) {
      if (board[combo[0]] !== "" && board[combo[0]] === board[combo[1]] && board[combo[1]] === board[combo[2]]) {
        return true;
      }
    }
    return false;
  };
  
 
const checkForTie = () => {
    const board = Gameboard.getBoard();
    for (let i = 0; i < board.length; i++) {
      if (board[i] === "") {
        return false;
      }
    }
    return true;
  };
  
  
  startButton.addEventListener("click", startGame);

  // read about AI tictactoe difficulty https://en.wikipedia.org/wiki/Minimax. 
  // I may add a slider for variation in difficulty later.
  const playAgainstAI = () => {
    player1 = Player(player1Input.value, "X");
    player2 = Player("AI", "O");
    currentPlayer = player1;
    Gameboard.resetBoard();
    renderBoard();
    status.textContent = `${currentPlayer.getName()}'s turn`;
    cells.forEach(cell => cell.addEventListener("click", handleCellClickAgainstAI));
    startButton.disabled = true;
  };
  
  const handleCellClickAgainstAI = e => {
    const index = e.target.dataset.cell;
    if (Gameboard.getBoard()[index] !== "") return;
    Gameboard.updateBoard(index, currentPlayer.getMarker());
    renderBoard();
    if (checkForWin()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClickAgainstAI));
      status.textContent = `${currentPlayer.getName()} wins!`;
      startButton.disabled = false;
      return;
    }
    if (checkForTie()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClickAgainstAI));
      status.textContent = "It's a tie!";
      startButton.disabled = false;
      return;
    }
    // the code below is useless but if I leave it out it causes problems
    if (currentPlayer === player1) {
      currentPlayer = player2;
      status.textContent = `${currentPlayer.getName()}'s turn`;
      handleCellClickAI();
    } else {
      currentPlayer = player1;
      status.textContent = `${currentPlayer.getName()}'s turn`;
    }
  };
  
  const handleCellClickAI = () => {
    const availableMoves = [];
    const board = Gameboard.getBoard();
    for (let i = 0; i < board.length; i++) {
      if (board[i] === "") {
        availableMoves.push(i);
      }
    }
    // AI is just picking a random square from avaiable moves.
    const randomIndex = Math.floor(Math.random() * availableMoves.length);
    const index = availableMoves[randomIndex];
    Gameboard.updateBoard(index, currentPlayer.getMarker());
    renderBoard();
    if (checkForWin()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClickAgainstAI));
      status.textContent = `${currentPlayer.getName()} wins!`;
      startButton.disabled = false;
      return;
    }
    if (checkForTie()) {
      cells.forEach(cell => cell.removeEventListener("click", handleCellClickAgainstAI));
      status.textContent = "It's a tie!";
      startButton.disabled = false;
      return;
    }
    currentPlayer = player1;
    status.textContent = `${currentPlayer.getName()}'s turn`;
  };
    
  document.querySelector("#play-ai-button").addEventListener("click", playAgainstAI);