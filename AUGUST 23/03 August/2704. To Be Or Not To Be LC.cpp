var expect = function(val) {
    return {
        notToBe: (val2) => {
            if(val===val2)
                throw new Error("Equal");
            else return true;
        },
        toBe: (val2) => {
            if (val !== val2) throw new Error("Not Equal");
            else return true;
        }
    }    
};
