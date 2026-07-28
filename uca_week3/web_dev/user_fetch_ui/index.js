const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");
worker.onmessage = function (event) {

    const users = event.data;

    if (users.length === 0) {
        usersDiv.innerHTML = "<p>No users found</p>";
        return;
    }

    users.forEach(user => {
        const p = document.createElement("p");
        p.textContent = `${user.name} - ${user.status}`;
        usersDiv.appendChild(p);
    });
};
worker.onerror = function () {
    usersDiv.innerHTML = "<p>Error processing data.</p>";
};

worker.postMessage("https://dummyjson.com/users");