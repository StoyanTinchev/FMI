package gui;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import logic.Animal;
import logic.AnimalInstance;
import logic.AnimalType;

import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;

public class AnimalController {

    private AnimalInstance[] samples;
    private Animal[] animals;
    private Random random;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDistribution;

    @FXML
    private Button btnQuit;

    @FXML
    private Button btnShowByAge;

    @FXML
    private Button btnShowEndangered;

    @FXML
    private Button btnShuffle;

    @FXML
    private TextArea txaResults;

    @FXML
    void btnDistributionOnClick(ActionEvent event) {
        txaResults.setText("");
        int[] countByRegions = new int[Animal.REGIONS.length];

        for (int i = 0; i < samples.length; i++) {
            for (int j = 0; j < countByRegions.length; j++) {
                if (animals[samples[i].getAnimalKey()].getRegion().equals(Animal.REGIONS[j])) {
                    countByRegions[j]++;
                }
            }
        }

        for (int i = 0; i < countByRegions.length; i++) {
            txaResults.appendText(String.format("%-20s%d%n", Animal.REGIONS[i], countByRegions[i]));
        }
    }

    @FXML
    void btnQuitOnClick(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnShowByAgeOnClick(ActionEvent event) {
        txaResults.setText("");

        AnimalInstance tmp;

        for (int i = 0; i < samples.length - 1; i++) {
            for (int j = 0; j < samples.length - i - 1; j++) {
                if (samples[j].getAnimalAge() < samples[j + 1].getAnimalAge()) {
                    tmp = samples[j];
                    samples[j] = samples[j + 1];
                    samples[j + 1] = tmp;
                }
            }
        }

        printArray();
    }

    private void printArray() {
        String result = "";

        for (int i = 0; i < samples.length; i++) {
            result += String.format("%s%n", samples[i].toString());
        }

        txaResults.appendText(result);
    }

    @FXML
    void btnShowEndangeredOnClick(ActionEvent event) {
        txaResults.setText("");

        int[] countByEndangered = new int[AnimalType.values().length];

        for (int i = 0; i < samples.length; i++) {
            if (animals[samples[i].getAnimalKey()].isEndangered()) {
                countByEndangered[animals[samples[i].getAnimalKey()].getAnimalType().ordinal()]++;
            }
        }

        for (int i = 0; i < countByEndangered.length; i++) {
            txaResults.appendText(String.format("%-20s%d%n", AnimalType.values()[i], countByEndangered[i]));
        }
    }

    @FXML
    void btnShuffleOnClIck(ActionEvent event) {
        txaResults.setText("");

        int index;
        AnimalInstance tmp;

        for (int i = 0; i < samples.length; i++) {
            index = random.nextInt(samples.length);
            tmp = samples[i];

            samples[i] = samples[index];
            samples[index] = tmp;
        }

        printArray();
    }

    @FXML
    void initialize() {
        assert btnDistribution != null : "fx:id=\"btnDistribution\" was not injected: check your FXML file 'view-animal.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'view-animal.fxml'.";
        assert btnShowByAge != null : "fx:id=\"btnShowByAge\" was not injected: check your FXML file 'view-animal.fxml'.";
        assert btnShowEndangered != null : "fx:id=\"btnShowEndangered\" was not injected: check your FXML file 'view-animal.fxml'.";
        assert btnShuffle != null : "fx:id=\"btnShuffle\" was not injected: check your FXML file 'view-animal.fxml'.";
        assert txaResults != null : "fx:id=\"txaResults\" was not injected: check your FXML file 'view-animal.fxml'.";

        animals = new Animal[]{
                new Animal("Тигър", AnimalType.MAMMAL, true, "Asia", true),
                new Animal("Фламинго", AnimalType.BIRD, false, "Africa", true),
                new Animal("Гущер", AnimalType.REPTILE, true, "Australia", true),
                new Animal("Пъстърва", AnimalType.FISH, false, "Europe", false),
                new Animal("Делфин", AnimalType.MAMMAL, false, "Australia", true),
                new Animal("Вълк", AnimalType.MAMMAL, true, "America", false)
        };

        random = new Random();
        samples = new AnimalInstance[20];

        int key;

        for (int i = 0; i < samples.length; i++) {
            key = random.nextInt(animals.length);
            samples[i] = new AnimalInstance(key, animals[key].getName(), random.nextInt(10, 31));
        }
    }

}
