Design and implement a set of classes that define the employees of a hospital.
Start by creating a HospitalEmployee super class, from which three other classes
will inherit.

The HospitalEmployee class will have the following components:
• name - a private String instance variable containing the employee's name
(taken in the object constructor)
• field - a private String instance variable containing the employee's
field (e.g. cardiology, oncology) (taken in the object constructor)
• onCall - a private boolean instance variable, set to true if the employee is
on call, and false otherwise. (initialized as false in the constructor)
• greeting - a function that takes no parameters, returns nothing, and prints a
string to standard output with the following format: "Hello, my name is
[name]. I work in [field]. How can I help you?"
• changeShift - a function that takes no parameters, returns nothing, and changes
the value of onCall. If onCall is false, changeShift should change it to
true. Otherwise, onCall should be changed to false.
• isOnCall - a function that takes no parameters and returns the value of
the boolean onCall.

There will be two classes inheriting from the HospitalEmployee class- Doctor
and Nurse. These classes will have the following components.

Doctor:
• A constructor that takes two String parameters, the Doctor's name and the
Doctor's field.
• checkCharts - a function that takes no parameters and returns nothing. If
the Doctor is on call, it should print out, "Charts have been checked." Otherwise,
the function should print, "Sorry, it's not my shift."

Nurse:
• A constructor that takes one String parameter, the Nurse's name. It should
set the variable field to "nursing."
• takeVitals - a function that takes no parameters and returns nothing. If
the Nurse is on call, it should print out, "Vitals have been taken." Otherwise,
the function should print, "Sorry, it's not my shift."

Create a driver class, named Hospital, that tests out these functions.
Create a Doctor object with the name "Jennifer Jackson" and the field
"pediatrics", as well as a Nurse with the name "Bobbie Blake". First, call
Bobbie's changeShift function. Then, On separate lines, print out Jennifer's
greeting, the ouput of her checkCharts function, Bobbie's greeting, and the output
of his takeVitals function.
