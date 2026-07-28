const worker = new Worker("worker.js");

async function FetchUser() {
    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }

        const data = await response.json();

        if (!data.users || data.users.length === 0) {
            console.error("No users returned from API.");
            return;
        }

        worker.postMessage(data.users);

    } catch (error) {
        console.error("Error:", error.message);
    }
}

worker.onmessage = function (event) {
    event.data.forEach(user => {
        console.log(`${user.name} - ${user.status}`);
    });
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};

FetchUser();