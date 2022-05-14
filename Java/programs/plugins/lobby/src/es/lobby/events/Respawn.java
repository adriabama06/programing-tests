package es.lobby.events;

import es.lobby.Main;
import es.lobby.config.Config;
import es.lobby.items.ItemMannager;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerRespawnEvent;
import org.bukkit.event.player.PlayerTeleportEvent;

public class Respawn implements Listener {
    private Main plugin;

    public Respawn(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public void onRespawn(PlayerRespawnEvent event){
        Player p = event.getPlayer();
        String world = Config.GetLocations().getString("lobby.world");
        if(!(world == null)) {
            FileConfiguration locs = Config.GetLocations();
            double x = locs.getDouble("lobby.x");
            double y = locs.getDouble("lobby.y");
            double z = locs.getDouble("lobby.z");
            float yaw = Float.parseFloat(locs.getString("lobby.yaw"));
            float pitch = Float.parseFloat(locs.getString("lobby.pitch"));
            p.teleport(new Location(Bukkit.getWorld(world), x, y, z, yaw, pitch), PlayerTeleportEvent.TeleportCause.PLUGIN);
        }
        p.getInventory().setItem(Config.GetItems().getInt("menu_de_juegos.slot") - 1, ItemMannager.menu_de_juegos);
    }
}
