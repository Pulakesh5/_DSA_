let initialValue
var createCounter = function(init) {
    initValue = init;
    return {
        increment: () => {
            return ++init;
        },
        decrement: () => {
            return --init;
        },
        reset: () => {
            return init = initValue;
        }
    }
};
