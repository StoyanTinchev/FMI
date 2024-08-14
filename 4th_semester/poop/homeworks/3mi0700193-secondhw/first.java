package org.fmi.problem1calendar;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.YearMonth;
import java.util.Optional;


public class HelloApplication extends Application {

    @Override
    public void start(Stage primaryStage) {
        TextInputDialog dialog = new TextInputDialog("MM/YYYY");
        dialog.setTitle("Calendar Input");
        dialog.setHeaderText("Enter Month and Year");
        dialog.setContentText("Please enter month and year (MM/YYYY):");

        Optional<String> result = dialog.showAndWait();
        result.ifPresentOrElse(dateString -> {
            String[] parts = dateString.split("/");
            if (parts.length == 2) {
                try {
                    int month = Integer.parseInt(parts[0]);
                    int year = Integer.parseInt(parts[1]);
                    showCalendar(month, year, primaryStage);
                } catch (NumberFormatException e) {
                    showErrorAlert("Invalid month or year. Please enter in MM/YYYY format.");
                }
            } else {
                showErrorAlert("Invalid format. Please enter in MM/YYYY format.");
            }
        }, () -> System.exit(0));
    }

    private void showCalendar(int month, int year, Stage stage) {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);

        final int NUM_DAYS = DayOfWeek.values().length;

        DayOfWeek[] days = DayOfWeek.values();
        for (int i = 0; i < NUM_DAYS; i++) {
            Text day = new Text(days[i % NUM_DAYS].toString().substring(0, 3));
            grid.add(day, i, 0);
        }

        YearMonth yearMonth = YearMonth.of(year, month);
        LocalDate firstOfMonth = yearMonth.atDay(1);
        int dayOfWeekOfFirst = firstOfMonth.getDayOfWeek().getValue() % NUM_DAYS;

        LocalDate today = LocalDate.now();
        boolean isCurrentMonth = today.getYear() == year && today.getMonthValue() == month;

        for (int i = 1; i <= yearMonth.lengthOfMonth(); i++) {
            LocalDate date = yearMonth.atDay(i);
            Text dateText = new Text(String.valueOf(date.getDayOfMonth()));

            if (isCurrentMonth && date.getDayOfMonth() == today.getDayOfMonth()) {
                dateText.setFill(javafx.scene.paint.Color.RED);
            }

            grid.add(dateText, (dayOfWeekOfFirst + i - 1) % NUM_DAYS, (dayOfWeekOfFirst + i - 1) / NUM_DAYS + 1);
        }

        Scene scene = new Scene(grid, 400, 400);
        stage.setTitle("Calendar for " + yearMonth.getMonth().toString() + " " + year);
        stage.setScene(scene);
        stage.show();
    }

    private void showErrorAlert(String content) {
        Alert alert = new Alert(Alert.AlertType.ERROR, content, ButtonType.OK);
        alert.setTitle("Error");
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}