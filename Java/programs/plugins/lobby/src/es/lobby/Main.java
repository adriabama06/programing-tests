package es.lobby;

import es.lobby.cmds.*;
import es.lobby.config.Config;
import es.lobby.events.*;
import es.lobby.items.*;
import es.lobby.menus.*;

import org.bukkit.Bukkit;
import org.bukkit.plugin.java.JavaPlugin;

public class Main extends JavaPlugin {
    @Override
    public void onEnable(){
        Bukkit.getConsoleSender().sendMessage(Util.color("&a&lPlugin started!!! at 0.0.1"));
        Config.ReloadConfig(this);
        Config.ReloadMessages(this);
        Config.ReloadLocations(this);
        Config.ReloadItems(this);
        Config.ReloadMenus(this);
        new test(this);
        new lobby(this);

        // Events
        new JoinListener(this);
        new Respawn(this);
        new InventoryEvent(this);
        new DeathEvent(this);

        // Menus
        servers.initalize();
        new serversClickListener(this);

        // Items
        ItemMannager.initalize();
        new ItemEvents(this);
    }
    @Override
    public void onDisable() {
        Bukkit.getConsoleSender().sendMessage(Util.color("&c&lPlugin ended... bye from 0.0.1"));
    }
}
