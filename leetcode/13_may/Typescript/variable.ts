let hello: string = "Hello World";
console.log(hello);

let number: number = 10;

function fail(msg: string): never {
  throw new Error("Error : " + msg);
}

function consoleError(msg: string): void {
  console.error("Error" + msg);
}

//fun
type str = string;
type bool = boolean;
type num = number;
type obj = object;
type nul = null;
type und = undefined;
type faltu = never;
type vo = void;


type user = {
    readonly _id: string;
    name: string;
    age: number;
    isAdult: boolean;
    gender?: boolean  // ? --> means optional 
    };

let user1 : user = {
    _id : "123",
    name :"rohan",
    age : 21,
    isAdult : true

}
user1.gender = false;

function Return(user): user{
    let User = {name: "Rahul", age: 20, isAdult: true};
    // let User1 :user = {"rahul", 20, true};

    return user;
}

Return({name: "Rahul", age: 20, isAdult: true});
// objects ${msg}


export{}