function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let handlers = [];

    function resolve(result) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = result;

        handlers.forEach(handle);
    }

    function reject(error) {
        if (state !== "pending") return;

        state = "rejected";
        value = error;

        handlers.forEach(handle);
    }

    function handle(handler) {
        if (state === "pending") {
            handlers.push(handler);
            return;
        }

        if (state === "fulfilled") {
            if (handler.onFulfilled) {
                const result = handler.onFulfilled(value);
                handler.resolveNext(result);
            } else {
                handler.resolveNext(value);
            }
        }

        if (state === "rejected") {
            if (handler.onRejected) {
                const result = handler.onRejected(value);
                handler.resolveNext(result);
            } else {
                handler.rejectNext(value);
            }
        }
    }

    this.then = function(onFulfilled, onRejected) {
        return new NewPromise((resolveNext, rejectNext) => {
            handle({
                onFulfilled: onFulfilled,
                onRejected: onRejected,
                resolveNext: resolveNext,
                rejectNext: rejectNext
            });
        });
    };

    this.catch = function(onRejected) {
        return this.then(null, onRejected);
    };

    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}

//sample setup
new NewPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});

// 50
