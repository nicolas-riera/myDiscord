const socketUrl = "ws://localhost:8080";
let socket = null;

function connectToServer(onMessageCallback) {
    socket = new WebSocket(socketUrl, "myDiscord_websocket");

    socket.onopen = () => {
        console.log("Connected");
    };

    socket.onmessage = (event) => {
        if (onMessageCallback) {
            onMessageCallback(event.data);
        }
    };

    socket.onclose = () => {
        setTimeout(() => connectToServer(onMessageCallback), 3000);
    };
}

function sendToServer(payload) {
    if (socket && socket.readyState === WebSocket.OPEN) {
        socket.send(typeof payload === "object" ? JSON.stringify(payload) : payload);
    }
}