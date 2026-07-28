self.onmessage = function (event) {
    const users = event.data;

    const result = users.map(user => ({
        name: `${user.firstName} ${user.lastName}`,
        status: user.active ? "Active" : "Inactive"
    }));

    self.postMessage(result);
};