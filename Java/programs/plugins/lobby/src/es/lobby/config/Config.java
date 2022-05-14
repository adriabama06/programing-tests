package es.lobby.config;

import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.bukkit.plugin.java.JavaPlugin;

import java.io.File;
import java.io.IOException;

public class Config {
    private static FileConfiguration Config;
    private static FileConfiguration Messages;
    private static FileConfiguration Locations;
    private static FileConfiguration Items;
    private static FileConfiguration Menus;


    public static FileConfiguration GetConfig() {
        return Config;
    }
    public static void SaveConfig(JavaPlugin plugin) {
        plugin.saveConfig();
        return;
    }
    public static void ReloadConfig(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "config.yml");
        if(!datFile.exists()) {
            plugin.getConfig().options().copyDefaults(true);
            plugin.saveConfig();
        }
        plugin.reloadConfig();
        Config = plugin.getConfig();
        return;
    }


    public static FileConfiguration GetMessages() {
        return Messages;
    }
    public static boolean SaveMessages(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "messages.yml");
        if(!datFile.exists()) {
            ReloadMessages(plugin);
            return false;
        }
        try {
            Messages.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadMessages(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "messages.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("messages.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Messages = dat;
        return true;
    }


    public static FileConfiguration GetLocations() {
        return Locations;
    }
    public static boolean SaveLocations(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "locations.yml");
        if(!datFile.exists()) {
            ReloadLocations(plugin);
            return false;
        }
        try {
            Locations.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadLocations(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "locations.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("locations.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Locations = dat;
        return true;
    }


    public static FileConfiguration GetItems() {
        return Items;
    }
    public static boolean SaveItems(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "items.yml");
        if(!datFile.exists()) {
            ReloadLocations(plugin);
            return false;
        }
        try {
            Items.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadItems(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "items.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("items.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Items = dat;
        return true;
    }


    public static FileConfiguration GetMenus() {
        return Menus;
    }
    public static boolean SaveMenus(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "menus.yml");
        if(!datFile.exists()) {
            ReloadLocations(plugin);
            return false;
        }
        try {
            Menus.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadMenus(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "menus.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("menus.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Menus = dat;
        return true;
    }
}