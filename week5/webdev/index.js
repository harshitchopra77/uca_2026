function* calculator(val) {
    let result = val;

    while (true) {
        const input = yield result;

        if (!input || typeof input !== "object") {
            yield "Invalid input";
            continue;
        }

        const { operation, value } = input;

        if (typeof value !== "number" || Number.isNaN(value)) {
            yield "Invalid input";
            continue;
        }

        switch (operation) {
            case "add":
                result += value;
                break;

            case "subtract":
                result -= value;
                break;

            case "multiply":
                result *= value;
                break;

            case "divide":
                if (value === 0) {
                    yield "Cannot divide by zero";
                    continue;
                }

                result /= value;
                break;

            default:
                yield "Invalid operation";
                continue;
        }
    }
}

const calc_obj = calculator(50);

console.log(calc_obj.next());
console.log(calc_obj.next({ operation: "add", value: 30 }));
console.log(calc_obj.next({ operation: "multiply", value: 2 }));
console.log(calc_obj.next({ operation: "add", value: "30" }));
console.log(calc_obj.next({ operation: "multiply", value: 0 }));
