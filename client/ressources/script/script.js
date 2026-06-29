connectToServer((rawMessage) => {
    console.log("Data received  :", rawMessage);
    
    const newParagraph = document.createElement("p");
    newParagraph.textContent = rawMessage;
    document.body.appendChild(newParagraph);
})

document.getElementById("bruh").addEventListener("click", () => {
    sendToServer("Bruh");
});