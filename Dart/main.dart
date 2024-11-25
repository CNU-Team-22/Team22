String sayHello({required String name,required int age,required String country}){
  return 'Hello $name, your age is $age, and you live in $country';
}

String sayHi(Map<String, String> userInfo){
    return "Hi ${userInfo['name']}";
  }

class Person{
  String name;
  int age;
  String team;
  
  Person({required this.name, required this.age, required this.team}){}

  void introduce(){
    print("Hi my name is $name, I'm $age years old and I'm team $team");
  }

  Person.createRedTeam({
    required String name,
    required int age
    }) : this.team = "red", 
      this.name = name, 
      this.age = age;
}
void main(){
  Person lee = Person(name: "lee", age: 22, team: "03")
  ..name = "Lee"
  ..age = 23;
  lee.introduce(); 
  Person kim = Person.createRedTeam(name: "kim", age: 20);
  kim.introduce();
}