import java.util.Objects;

class Patient {

    private int id;
    private String lastName;
    private String firstName;
    private String middleName;
    private String address;
    private String phone;
    private int medicalCardNumber;
    private String diagnosis;

    public Patient() {
    }

    public Patient(int id, String lastName, String firstName, String middleName, 
                  String address, String phone, int medicalCardNumber, String diagnosis) {
        this.id = id;
        this.lastName = lastName;
        this.firstName = firstName;
        this.middleName = middleName;
        this.address = address;
        this.phone = phone;
        this.medicalCardNumber = medicalCardNumber;
        this.diagnosis = diagnosis;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public String getLastName() {
        return lastName;
    }
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getMiddleName() {
        return middleName;
    }
    public void setMiddleName(String middleName) {
        this.middleName = middleName;
    }

    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhone() {
        return phone;
    }
    public void setPhone(String phone) {
        this.phone = phone;
    }

    public int getMedicalCardNumber() {
        return medicalCardNumber;
    }
    public void setMedicalCardNumber(int medicalCardNumber) {
        this.medicalCardNumber = medicalCardNumber;
    }

    public String getDiagnosis() {
        return diagnosis;
    }
    public void setDiagnosis(String diagnosis) {
        this.diagnosis = diagnosis;
    }

    @Override
    public String toString() {
        return "Patient{" +
                "id=" + this.getId() +
                ", lastName='" + this.getLastName() + '\'' +
                ", firstName='" + this.getFirstName() + '\'' +
                ", middleName='" + this.getMiddleName() + '\'' +
                ", address='" + this.getMiddleName() + '\'' +
                ", phone='" + this.getPhone() + '\'' +
                ", medicalCardNumber=" + this.getMedicalCardNumber() +
                ", diagnosis='" + this.getDiagnosis() + '\'' +
                '}';
    }

    public int hashCode() {
        return Objects.hash(this.getId(),
                this.getLastName(),
                this.getFirstName(),
                this.getMiddleName(),
                this.getMiddleName(),
                this.getPhone(),
                this.getMedicalCardNumber(),
                this.getDiagnosis());
    }

    public void isDiagnosis(String diagnosis) {

        if(this.getDiagnosis().equals(diagnosis))
            System.out.println(this.toString());

    }

    public void isMedicalNumberRange(int startNumber, int endNumber) {

        int thisMedicalCardNumber = this.getMedicalCardNumber();
        if(startNumber <= thisMedicalCardNumber && endNumber >= thisMedicalCardNumber )
            System.out.println(this.toString());

    }

}

public class lab1{ 
      
    public static void main (String args[]){
          
        Patient[] arrPatient = new Patient[3];
        arrPatient[0] = new Patient(1, "Иванов", "Иван", "Иванович", 
                "ул. Ленина, 123", "+7-999-123-45-67", 1001, "Грипп");
        
        arrPatient[1] = new Patient(2, "Петров", "Петр", "Петрович", 
                "ул. Пушкина, 45", "+7-999-234-56-78", 1002, "Ангина");
        
        arrPatient[2] = new Patient(3, "Сидорова", "Мария", "Ивановна", 
                "ул. Гагарина, 67", "+7-999-345-67-89", 1003, "Грипп");

        System.out.println("\n=== ПАЦИЕНТЫ С ДИАГНОЗОМ 'ГРИПП' ===");
        for (Patient patient : arrPatient) {
            patient.isDiagnosis("Грипп");
        }    

        System.out.println("\n=== ПАЦИЕНТЫ С НОМЕРОМ МЕДКАРТЫ ОТ 1002 ДО 1004 ===");
        for (Patient patient : arrPatient) {
            patient.isMedicalNumberRange(1002, 1004);
        }   

    }

}
