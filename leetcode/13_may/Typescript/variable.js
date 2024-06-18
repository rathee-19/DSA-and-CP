var hello = "Hello World";
console.log(hello);
var number = 10;
function fail(msg) {
    throw new Error("Error : " + msg);
}
function consoleError(msg) {
    console.error("Error" + msg);
}
function Return(user) {
    var User = { name: "Rahul", age: 20, isAdult: true };
    // let User1 :user = {"rahul", 20, true};
    console.log("User : ", User);
    return user;
}
Return({ name: "Rahul", age: 20, isAdult: true });
// objects ${msg}
consoleError("Error");

