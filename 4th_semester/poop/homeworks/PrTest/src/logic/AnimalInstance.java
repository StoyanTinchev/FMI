package logic;

public class AnimalInstance {

    private static int count = 0;
    private final String INSTANCE_ID;
    private int animalKey;
    private String animalName;
    private int animalAge;

    public AnimalInstance(int animalKey, String animalName, int animalAge) {
        setAnimalKey(animalKey);
        setAnimalName(animalName);
        setAnimalAge(animalAge);

        INSTANCE_ID = String.format("%s %03d", animalName, ++count);
    }

    public int getAnimalKey() {
        return animalKey;
    }

    public void setAnimalKey(int animalKey) {
        if (animalKey >= 0) {
            this.animalKey = animalKey;
        } else {
            this.animalKey = 0;
        }
    }

    public String getAnimalName() {
        return animalName;
    }

    public void setAnimalName(String animalName) {
        if (animalName != null && !animalName.isEmpty()) {
            this.animalName = animalName;
        } else {
            this.animalName = "Unknown";
        }
    }

    public int getAnimalAge() {
        return animalAge;
    }

    public void setAnimalAge(int animalAge) {
        if (animalAge >= 0) {
            this.animalAge = animalAge;
        } else {
            this.animalAge = 0;
        }
    }

    public String getINSTANCE_ID() {
        return INSTANCE_ID;
    }

    @Override
    public String toString() {
        return String.format("%s, Възраст: %d", INSTANCE_ID, animalAge);
    }
}
