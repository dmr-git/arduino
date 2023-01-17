/*****
  EEPROM writing example from p. 185 of "Beginning C for Arduino"
*****/

#include <EEPROM.h>

#define DEBUG 1

const int MAXPEOPLE = 7;  // to limit the number of allowed companies

struct servicePeople {
  int ID;
  char Name[20];
  char PW[10];
  long Phone;
};

union servicePeopleUnion {
  int testID;
  struct servicePeople testServicePeople;
} myUnion;

servicePeople myPeople[MAXPEOPLE] = {
  { 0, "This is dummy data", "admin", 5555555 },
  { 101, "Kack Lawn Service", "Clowder", 2345678 },
  { 222, "Janes Plants", "Noah", 4202513 },
  { 333, "Terrys Pool Service", "Billings", 4301832 }
};

// function declarations do I can test compile as I go along
void DataDump(struct servicePeople temp);
int FindEepromTop();
int ReadIntFlag();
void ReadOneRecord(int index);
void WriteFirstRecord();
void WriteOneRecord(int index);
void TerminationStep();

int loopCounter = 0;        // number of passes to make theough the loop
int initFlag = 0;           // has EEPROM been initialized?
struct servicePeople temp;  // a temporary structure


void setup() {
  int eepromMax;
  int i;

  Serial.begin(9600);
  eepromMax = FindEepromTop();

#ifdef DEBUG
  Serial.print("eepromMax = ");
  Serial.println(eepromMax);
#endif

  initFlag = ReadIntFlag();  // Initialized?


#ifdef DEBUG
  Serial.print("flag = ");
  Serial.println(initFlag);
#endif
  //  write the records to EEPROM
  for (i = 0; i < MAXPEOPLE; i++) {
    WriteOneRecord(i);
  }
}

void loop() {
  static int eepromIndex = 1;  // assume there are records
  initFlag = ReadIntFlag();  // Initialized?
  loopCounter++;
  if (initFlag > 0) {  // there are records to read
    ReadOneRecord(eepromIndex++);
    if (myUnion.testServicePeople.ID != 0) {  //read some real data (remember, the first record is junk)
      DataDump(myUnion.testServicePeople);
    }
  } else {
    eepromIndex++;  // make sure the loop can end with no records
  }
#ifdef DEBUG
  Serial.println("================");
#endif
  if (eepromIndex == MAXPEOPLE) {
    TerminationStep();
  }
}

/*****
  Purpose: send the data stored in parameter to the serial monitor
  Parameter list:
    struct servicePeople temp  // the data to be displayed
  Return: void
*****/
void DataDump(struct servicePeople temp) {
  Serial.println();
  Serial.print("ID = ");
  Serial.print(temp.ID);
  Serial.print("    Name = ");
  Serial.print(temp.Name);
  Serial.print("    PW = ");
  Serial.print(temp.PW);
  Serial.print("    Phone = ");
  Serial.println(temp.Phone);
}

/*****
  Purpose: find out how much EEPROM memory is available
  E2END is an Arduino symbolic constant which represents the largest valid address 
  in EEPROM memory.  1 ia added as the memory addresses starts from 0.
  Return: the amount of EEPROM memory as an integer
*****/
int FindEepromTop() {
  return E2END + 1;
}

/*****
  Purpose: Reads the first 2 bytes from EEPROM and returns the integer found there
  Return: 0 if no records in EEPROM memory, 1 if there are
*****/
int ReadIntFlag() {
   return 1;
}

/*****
  Purpose: Read one serviceperson record from EEPROM
  Parameter list:
    int index   the element of the myPerson[] array to read from EEPROM
  Return: void  
*****/
void ReadOneRecord(int index) {
  byte *bPtr;
  int i;
  int offset;

  offset = index * sizeof(servicePeople);     // must offset from 0 in EEPROM
  bPtr = (byte *)&myUnion.testServicePeople;  // where to place the data read
  for (i = 0; i < sizeof(temp); i++) {
    *bPtr = EEPROM.read(offset + i);
    bPtr++;
  }
}

//
void WriteFirstRecord() {
  return;
}

/*****
  Purpose: Write one record from the myPeople[] array to EEPROM
  Parameter list:
    int index   The element of the myPeople[] array to write
  Return: void  
*****/
void WriteOneRecord(int index) {
  byte *b;  // will be initialized to point to the lvalue of where this record is stored in SRAM
  int i;
  int offset = index * sizeof(servicePeople);
  b = (byte *)&myPeople[index];  //going to write this record
  for (i = 0; i < sizeof(servicePeople); i++) {
    EEPROM.write(i + offset, *b++);
  }
}

//
void TerminationStep() {
  Serial.flush();
  exit(0);
}
